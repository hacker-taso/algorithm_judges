#include<iostream>
#include<algorithm>
#include<vector>
// I've read the solution
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
#define SLASH 0
#define BSLASH 1
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int dirmap[4][2] = {{DOWN, UP}, {UP, DOWN}, {RIGHT, LEFT}, {LEFT, RIGHT}};
char mirrormap[4] = {'/', '/', '\\', '\\'};
struct position {
  int w, a, b;
};
vector<position> adj;
int R, C, maxn;
char sol[100][100];
void init() {
  memset(sol, '.', sizeof(sol));
}

struct cust_greater {
  bool operator() (position p1, position p2) {
    return p1.w < p2.w;
  }
};

// y, x, dir
position getFirstPos(int person) {
  if (person <= C)
    return {-1, person-1, DOWN};
  person-=C;
  if (person <= R)
    return {person-1, C, LEFT};
  person-=R;
  if (person <= C)
    return {R, C-person, UP};
  person-=C;
  return {R-person, -1, RIGHT};
}
void move(int& y, int& x, int dir) {
  y = y+dy[dir], x = x+dx[dir];
}

void solve() {
  sort(adj.begin(), adj.end(), cust_greater());
  for (auto [w, s, e]: adj) {
    auto [y, x, dir] = getFirstPos(s);
    move(y, x, dir);
    while (0<=y && y<R && 0<=x && x<C) {
      if (sol[y][x] == '.')
        sol[y][x] = mirrormap[dir];
      int sltype = sol[y][x] == '/' ? SLASH : BSLASH;
      dir = dirmap[dir][sltype];
      move(y, x, dir);
    }
    auto [ey, ex, edir] = getFirstPos(e);
    if (ey != y || ex != x) {
      cout << "IMPOSSIBLE" <<endl;
      return;
    }
  }
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      if (sol[y][x] == '.')
        sol[y][x] = '/';
      cout << sol[y][x];
    }
    cout <<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, tmp, tmp2;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cin >> R >> C;
    maxn = 2*(R+C);
    adj.clear();
    for (int j=0; j<(R+C); j++) {
      cin >> tmp >> tmp2;
      if ((maxn + tmp - tmp2)%maxn < (maxn + tmp2-tmp)%maxn) {
        adj.push_back({(maxn + tmp - tmp2)%maxn, tmp2, tmp});
      } else {
        adj.push_back({(maxn + tmp2 - tmp)%maxn, tmp, tmp2});
      }
    }
    cout << "Case #" << i << ": " << endl;
    solve();
  }
}
