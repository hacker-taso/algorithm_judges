// We can brute force the arrangements of hedges and dfs from each man
// time complexity: 100(T) * 2^16(arrangement) * 8(number of couples) * 16(dfs) ~= 800,000,000
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int R, C;
vector<string> board;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int adj[64];

void goNext(int& y, int& x) {
  if (y == 0) {
    x += 1;
    if (x == C+1)
      y+=1;
  } else if (y == R+1) {
    x -= 1;
    if (x == 0)
      y-=1;
  } else if (x == 0) {
    y -= 1;
    if (y == 0)
      x+=1;
  } else if (x == C+1) {
    y += 1;
    if (y == R+1)
      x-=1;
  }
}

int dfs(int y, int x, int from) {
  if (board[y][x] != '/' && board[y][x] != '\\')
    return board[y][x];
  if (board[y][x] == '/') {
    if (from == UP) return dfs(y, x-1, RIGHT);
    if (from == DOWN) return dfs(y, x+1, LEFT);
    if (from == LEFT) return dfs(y-1, x, DOWN);
    if (from == RIGHT) return dfs(y+1, x, UP);
  } else {
    if (from == UP) return dfs(y, x+1, LEFT);
    if (from == DOWN) return dfs(y, x-1, RIGHT);
    if (from == LEFT) return dfs(y+1, x, UP);
    if (from == RIGHT) return dfs(y-1, x, DOWN);
  }
  return -1;
}

int getFrom(int i) {
  if (i < C) return UP;
  if (i < C+R) return RIGHT;
  if (i < 2*C+R) return DOWN;
  return LEFT;
}

bool checkBoard() {
  vector<bool> done(2*(R+C), 0);
  int y=0, x=1;
  for (int i=0; i<2*(R+C); i++) {
    if (done[i]) {
      goNext(y, x);
      continue;
    }
    int from = getFrom(i);
    int ny = from == UP ? y+1 : (from == DOWN ? y-1 : y);
    int nx = from == LEFT ? x+1 : (from == RIGHT ? x-1 : x);
    int res = dfs(ny, nx, from);
    if (adj[i] != res) {
        return false;
    }
    done[i] = done[adj[i]] = true;
    goNext(y, x);
  }
  return true;
}

void getYX(int idx, int& y, int& x) {
  y = 1 + idx / C;
  x = 1 + idx % C;
}
bool makeAndTry(int idx) {
  if (idx == R * C) {
    return checkBoard();
  }
  int y, x;
  getYX(idx, y, x);
  board[y][x] = '/';
  if (makeAndTry(idx+1))
    return true;
  board[y][x] = '\\';
  return makeAndTry(idx+1);
}

void solve() {
  if (!makeAndTry(0)) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      cout << board[y+1][x+1];
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, tmp, tmp2, y, x;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> R >> C;
    board = vector<string>(R+2, string(C+2, ' '));
    y = 0, x = 1;
    for (int j=0; j<2*(R+C); j++) {
      board[y][x] = j;
      goNext(y, x);
    }
    memset(adj, 0, sizeof(adj));
    for (int j=0; j<R+C; j++) {
      cin >> tmp;
      cin >> tmp2;
      adj[tmp-1] = tmp2-1;
      adj[tmp2-1] = tmp-1;
    }
    cout << "Case #" << i << ": " <<endl;
    solve();
  }
}
