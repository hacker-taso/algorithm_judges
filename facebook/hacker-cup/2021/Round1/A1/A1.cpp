#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
#include<map>
#include<cmath>
#include<string>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N;
string W;
vector<int> arr;
void init() {
  cin >> N;
  cin >> W;
}

void solve() {
  char cur = -1;
  int cnt = 0;
  for (char c: W) {
    if (c == 'F') continue;
    if (cur == -1) {
      cur = c;
      continue;
    }
    if (c != cur) {
      cur = c;
      cnt++;
    }
  }
  cout << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": ";
    solve();
  }
}
