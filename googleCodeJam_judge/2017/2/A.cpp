#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, P;
vector<int> arr;

bool dfs(vector<int>& cnts, int i, int curV) {
  if (i == P) {
    return false;
  }
  for (int j=1; j<=cnts[i]; j++) {
    if ((curV + cnts[i]*j)%P == 0) {
      cnts[i] -= j;
      return true;
    }
    bool res = dfs(cnts, i+1, (curV + cnts[i]*j)%P);
    if (res) {
      cnts[i] -= j;
      return true;
    }
  }
  return false;
}

int solve() {
  int sol = 0;
  vector<int> cnts(P, 0);
  for (int i=0; i<arr.size(); i++)
    cnts[arr[i]]++;
  sol += cnts[0];
  for (int i=P-1; 0<i; i--) {
    int usedCnt = min(cnts[i], cnts[P-i]);
    if (i == P-i)
      usedCnt = cnts[i]/2;
    sol += usedCnt;
    cnts[i] -= usedCnt;
    cnts[P-i] -= usedCnt;
    int usedCnt2 = 0;
    for (int j=1; j<=cnts[i]; j++) {
      if ((i*j)%P == 0) {
        sol++;
        usedCnt2 = j;
      } 
    }
    cnts[i] -= usedCnt2;
  }
  // 3 2 1 % 4, 2 1 % 3, 1 % 2
  sol += dfs(cnts, 1, 0);
  sol += dfs(cnts, 1, 0);
  sol += dfs(cnts, 1, 0);

  for (int i=P-1; 0<i; i--) {
    if (cnts[i] != 0) {
      sol += 1;
      break;
    }
  }
  return sol;
}

int main() {
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> P;
    arr.resize(N);
    for (int j=0; j<N; j++) {
      cin >> arr[j];
      arr[j] %= P;
    }
    cout << "Case #" << i << ": " << solve() <<endl;
  }
}