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
int A, B;
vector<int> getPrimeNumberMap(){
  int maxNum = 100000;
  vector<int> primeNumberMap(maxNum+1, 1);
  primeNumberMap[0] = 0;
  primeNumberMap[1] = 1;
  for (vector<bool>::size_type i=2; i*i<=maxNum;i++){
    if(primeNumberMap[i] == 1){
      for(int j=i*i; j<=maxNum; j+=i){
        primeNumberMap[j] = i;
      }
    }
  }
  return primeNumberMap;
}

int solve() {
  int sol = 0;
  vector<int> pmap = getPrimeNumberMap();
  for (int i=A; i<=B; i++) {
    int j = i;
    int cnt = 1;
    while (pmap[j] != 1) {
      j = j/pmap[j];
      cnt++;
    }
    if (cnt != 1 && pmap[cnt] == 1)
      sol++;
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> A >> B;
  cout << solve() << endl;
}
