#include<iostream>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include <string>
using namespace std;
void SA_IS(unsigned char *s, int *SA, int n, int K, int cs);
vector<vector<int>> suffixArrs;
int N;
vector<string> ss;
string curS;
string query;

int comp(string& query, int idx) {
  int i=0;
  while (i < query.size() && idx + i < curS.size()) {
    if (query[i] == curS[idx+i]) {
      i++;
      continue;
    }
    return curS[idx+i] < query[i] ? 1 : -1;
  }
  return 0;
}

bool solve(vector<int>& suffixArr) {
  int lo = 0, hi = suffixArr.size();
  while (lo < hi) {
    int mid = (lo+hi)/2;
    int start = suffixArr[mid];
    int compRes = comp(query, start);
    if (0 < compRes || (compRes == 0 && curS.size() - start < query.size())) { // suf < query
      lo = mid+1;
    } else if (compRes < 0) {
      hi = mid;
    } else {
      return true;
    }
  }
  return false;
}


const int maxn = 10001;
int sa[maxn];
unsigned char *s;
int n;

int main() {
  ios_base::sync_with_stdio(false);
  int Q;
  cin >> N;
  ss.resize(N); suffixArrs.resize(N);
  for (int i=0; i<N; i++) {
    cin >> ss[i];
    n = ss[i].size();
    s = (unsigned char*) ss[i].c_str();
    SA_IS(s, sa, n + 1, 256, 1);
    suffixArrs[i].resize(n);
    for (int j=0; j<n; j++)
      suffixArrs[i][j] = sa[j];
  }
  cin >> Q;
  for (int i=0; i<Q; i++) {
    int cnt = 0;
    cin >> query;
    for (int j=0; j<N; j++) {
      curS = ss[j];
      cnt += solve(suffixArrs[j]);
    }
    cout << cnt << endl;
  }
}

unsigned char mask[] = { 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01 };
#define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
#define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:((unsigned char *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))

// find the start or end of each bucket
void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, sum = 0;
    for (i = 0; i <= K; i++)
        bkt[i] = 0; // clear all buckets
    for (i = 0; i < n; i++)
        bkt[chr(i)]++; // compute the size of each bucket
    for (i = 0; i <= K; i++) {
        sum += bkt[i];
        bkt[i] = end ? sum : sum - bkt[i];
    }
}
// compute SAl
void induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); // find starts of buckets
    for (i = 0; i < n; i++) {
        j = SA[i] - 1;
        if (j >= 0 && !tget(j))
            SA[bkt[chr(j)]++] = j;
    }
}
// compute SAs
void induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt, int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); // find ends of buckets
    for (i = n - 1; i >= 0; i--) {
        j = SA[i] - 1;
        if (j >= 0 && tget(j))
            SA[--bkt[chr(j)]] = j;
    }
}

// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
void SA_IS(unsigned char *s, int *SA, int n, int K, int cs) {
    int i, j;
    unsigned char *t = (unsigned char *) malloc(n / 8 + 1); // LS-type array in bits
    // Classify the type of each character
    tset(n-2, 0);
    tset(n-1, 1); // the sentinel must be in s1, important!!!
    for (i = n - 3; i >= 0; i--)
        tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
    // stage 1: reduce the problem by at least 1/2
    // sort all the S-substrings
    int *bkt = (int *) malloc(sizeof(int) * (K + 1)); // bucket array
    getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
    for (i = 0; i < n; i++)
        SA[i] = -1;
    for (i = 1; i < n; i++)
        if (isLMS(i))
            SA[--bkt[chr(i)]] = i;
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    // compact all the sorted substrings into the first n1 items of SA
    // 2*n1 must be not larger than n (proveable)
    int n1 = 0;
    for (i = 0; i < n; i++)
        if (isLMS(SA[i]))
            SA[n1++] = SA[i];
    // find the lexicographic names of all substrings
    for (i = n1; i < n; i++)
        SA[i] = -1; // init the name array buffer
    int name = 0, prev = -1;
    for (i = 0; i < n1; i++) {
        int pos = SA[i];
        bool diff = false;
        for (int d = 0; d < n; d++)
            if (prev == -1 || chr(pos+d) != chr(prev+d) || tget(pos+d) != tget(prev+d)) {
                diff = true;
                break;
            } else if (d > 0 && (isLMS(pos+d) || isLMS(prev+d)))
                break;
        if (diff) {
            name++;
            prev = pos;
        }
        pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
        SA[n1 + pos] = name - 1;
    }
    for (i = n - 1, j = n - 1; i >= n1; i--)
        if (SA[i] >= 0)
            SA[j--] = SA[i];
    // stage 2: solve the reduced problem
    // recurse if names are not yet unique
    int *SA1 = SA, *s1 = SA + n - n1;
    if (name < n1)
        SA_IS((unsigned char*) s1, SA1, n1, name - 1, sizeof(int));
    else
        // generate the suffix array of s1 directly
        for (i = 0; i < n1; i++)
            SA1[s1[i]] = i;
    // stage 3: induce the result for the original problem
    bkt = (int *) malloc(sizeof(int) * (K + 1)); // bucket array
    // put all left-most S characters into their buckets
    getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
    for (i = 1, j = 0; i < n; i++)
        if (isLMS(i))
            s1[j++] = i; // get p1
    for (i = 0; i < n1; i++)
        SA1[i] = s1[SA1[i]]; // get index in s
    for (i = n1; i < n; i++)
        SA[i] = -1; // init SA[n1..n-1]
    for (i = n1 - 1; i >= 0; i--) {
        j = SA[i];
        SA[i] = -1;
        SA[--bkt[chr(j)]] = j;
    }
    induceSAl(t, SA, s, bkt, n, K, cs, false);
    induceSAs(t, SA, s, bkt, n, K, cs, true);
    free(bkt);
    free(t);
}
