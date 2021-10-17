//mistake: q.top() -> q.front()
//mistake2: int return function without returns
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
#define WALL '#'
#define EMPTY '.'
#define JIHOON 'J'
#define FIRE 'F'
int R, C;
vector<string> board;
int board2[1000][1000];
bool visited[1000][1000];
struct point {
  int y, x, d;
};
void init() {
  memset(board2, -1, sizeof(board2));
  string tmp;
  cin >> R >> C;
  board.resize(R);
  for (int i=0; i<R; i++) {
    cin >> board[i];
    for (int j=0; j<C; j++) {
      if (board[i][j] == WALL)
        board2[i][j] = -2;
    }
  }
}

bool isValid(int y, int x) {
  return 0<=y && y<R && 0<=x && x<C && !visited[y][x] && board2[y][x] != -2;
}

bool isGoal(int y, int x) {
  return 0 == y || 0 == x || y == R-1 || x == C-1;
}

void bfsFire(int oy, int ox) {
  queue<point> q;
  q.push({oy, ox, 0});
  while (!q.empty()) {
    auto [y, x, d] = q.front();
    q.pop();
    if (visited[y][x])
      continue;
    visited[y][x] = true;
    if (board2[y][x] == -1)
      board2[y][x] = d;
    else if (board2[y][x] <= d)
      continue;
    else
      board2[y][x] = d;
    for(int i=0; i<4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (isValid(ny, nx))
        q.push({ny, nx, d+1});
    }
  }
}

int bfsJihoon(int oy, int ox) {
  queue<point> q;
  q.push({oy, ox, 0});
  while (!q.empty()) {
    auto [y, x, d] = q.front();
    q.pop();
    if (visited[y][x])
      continue;
    visited[y][x] = true;
    if (board2[y][x]!=-1 && board2[y][x]<=d)
      continue;
    if (isGoal(y, x)) {
      return d+1;
    }
    for(int i=0; i<4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (isValid(ny, nx))
        q.push({ny, nx, d+1});
    }
  }
  return -1;
}

void solve() {
  int jy, jx;
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      if (board[y][x] == JIHOON) {
        jy = y, jx = x;
      }
    }
  }
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      if (board[y][x] == FIRE) {
        memset(visited, 0, sizeof(visited));
        bfsFire(y, x);
      }
    }
  }
  memset(visited, 0, sizeof(visited));
  int res = bfsJihoon(jy, jx);
  if (res == -1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
