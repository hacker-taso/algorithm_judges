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
#include<unordered_map>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int R;
int C;
int K;
vector<string> board;
void init() {
  cin >> R >> C >> K;
  board = vector<string>(R);
  for (int i=0; i<R; i++)
    cin >> board[i];
}

void solve() {
  K--;
  vector<vector<int>> ups(R, vector<int>(C, 0));
  vector<vector<int>> downs(R, vector<int>(C, 0));
  vector<int> ups2(R, 0);
  vector<int> downs2(R, 0);
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      if (y == 0)
        ups[y][x] = board[y][x] == 'X';
      else
        ups[y][x] = (board[y][x] == 'X') + ups[y-1][x];
      if (y == 0)
        downs[R-y-1][x] = board[R-y-1][x] == 'X';
      else
        downs[R-y-1][x] = (board[R-y-1][x] == 'X') + downs[R-y][x];
    }
  }
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      int targety = max(0, K-y);
      ups2[y] += ups[targety][x] <= K ? (board[targety][x] == 'X') : 0;
      targety = min(K+y, R-1);
      downs2[y] += downs[targety][x] < R-K ? (board[targety][x] == 'X') : 0;
      cout << y << ":" << x << ":" << (ups[targety][x] <= K ? (board[targety][x] == 'X') : 1) << ":" << (downs[targety][x] < R-K+1 ? (board[targety][x] == 'X') : 1) <<endl;
    }
  }
  int sol = numeric_limits<int>::max();
  for (int y=0; y<R; y++){
    sol = min(ups2[y]+y, sol);
    sol = min(downs2[y]+y, sol);
  }
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": ";
    solve();
  }
}
