#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> getSuffixArr(const string& s);
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
      cout << curS << ":" << query <<endl;
      return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int Q;
  cin >> N;
  ss.resize(N); suffixArrs.resize(N);
  for (int i=0; i<N; i++) {
    cin >> ss[i];
    suffixArrs[i] = getSuffixArr(ss[i]);
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


struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t):
        group(_group), t(_t) {}
    bool operator() (int a, int b) {
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};

vector<int> getSuffixArr(const string& s) {
    int n = s.size();
    vector<int> group(n+1);
    int t=1;
    for (int i=0; i<n; i++) group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for (int i=0; i<n; i++) perm[i] = i;
    while (t<n) {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t *= 2;
        if (t>= n) break;
        vector<int> newGroup(n+1);
        newGroup[perm[0]] = 0;
        newGroup[n] = -1;
        for (int i=1; i<n; i++) {
            if (compareUsing2T(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]]+1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
    }
    return perm;
}