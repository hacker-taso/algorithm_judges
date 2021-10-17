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
void init() {
  cin >> A >> B;
}

void solve() {
  if (B==1) {
    cout << "NO" <<endl;
    return;
  }
  cout << "YES" <<endl;
  cout << (long long)A*(B-1) << " " << (long long)A*(B+1) << " " << (long long)2*A*B <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    solve();
  }
}
