#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int arr[100000];
vector<bool> pnmap, pnmap2;
vector<int> primes_tmp, primes;
int n;
void init() {
  cin >> n;
  for (int i=0; i<n; i++)
    cin >> arr[i];
}

vector<bool> getPrimeNumberMap(){
  int maxNum = 40000;
  vector<bool> primeNumberMap(maxNum+1, true);
  primeNumberMap[0] = false;
  primeNumberMap[1] = false;
  for (vector<bool>::size_type i=2; i*i<=maxNum;i++){
    for(int j=i*i; j<=maxNum; j+=i){
      primeNumberMap[j] = false;
    }
  }
  return primeNumberMap;
}

vector<bool> getPrimeNumberMap2(){
  int maxNum = 1004000000;
  int sz = 4000000;
  vector<bool> primeNumberMap(sz+1, true);
  for (int p: primes_tmp){
    int first = 1000000000 - (1000000000 % p);
    for(int j=first; j<=maxNum; j+=p){
      if (j < 1000000000) continue;
      primeNumberMap[j-1000000000] = false;
    }
  }
  return primeNumberMap;
}


void solve() {
  if (n==1) {
    cout << 0 << endl;
    return;
  }
  int minV = 1400305337;
  int minIdx = -1;
  for (int i=0; i<n; i++) {
    if (arr[i] < minV) {
      minIdx = i;
      minV = arr[i];
    }
  }

  cout << n-1 <<endl;
  for (int i=0; i<n; i++) {
    if (i==minIdx) continue;
    cout << minIdx+1 << " " << i+1 << " " << minV << " " << primes[i] << endl;
  }
}

int main() {
  pnmap = getPrimeNumberMap();
  for (int i=0; i<40000; i++) {
    if (pnmap[i])
      primes_tmp.push_back(i);
  }
  pnmap2 = getPrimeNumberMap2();
  for (int i=0; i<4000000; i++) {
    if (pnmap2[i])
      primes.push_back(i+1000000000);
  }
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    solve();
  }
}
