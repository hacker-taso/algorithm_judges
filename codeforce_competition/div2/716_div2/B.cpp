#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007
using namespace std;
int n, k;

int solve() {
  long long int sol = 1;
  for (int i=0; i<k; i++) {
    sol = (sol * n) % MOD;
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n >> k;
    cout << solve() <<endl;
  }
}
