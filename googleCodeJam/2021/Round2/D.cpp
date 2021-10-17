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
int R, C, F, S;
vector<string> board1;
vector<string> board2;
int swapcnt[100][100];
void init() {
  cin >> R >> C >> F >> S;
  board1.resize(R);
  board2.resize(R);
  for (int i=0; i<R; i++)
    cin >> board1[i];
  for (int i=0; i<R; i++)
    cin >> board2[i];
}

bool swappable(int y1, int x1, int y2, int x2) {
  if (y2 < 0 || R <= y2 || x2 < 0 || C <= x2)
    return false;
  return (board1[y1][x1] != board1[y2][x2]) && (board1[y1][x1] == board2[y2][x2])
    && board1[y2][x2] == board2[y1][x1];
}

int solve() {
  int sol = 0;
  while (true) {
    bool anyUpdated = false;
    for (int j=1; j<=4; j++) {
      bool updated = false;
      memset(swapcnt, 0, sizeof(swapcnt));
      for (int y=0; y<R; y++) {
        for (int x=0; x<C; x++) {
          int swapy, swapx;
          for (int i=0; i<4; i++) {
            int ny = y+dy[i], nx = x+dx[i];
            if (swappable(y, x, ny, nx)) {
              swapcnt[y][x]++;
              swapy = ny, swapx = nx;
            }
          }
          if (swapcnt[y][x] == j) {
            updated = true;
            anyUpdated = true;
            swap(board1[swapy][swapx], board1[y][x]);
            sol++;
            break;
          }
        }
        if (updated)
          break;
      }
      if (updated)
        break;
    }
    if (!anyUpdated)
      break;
  }
  for (int y=0; y<R; y++) {
    for (int x=0; x<C; x++) {
      if (board1[y][x] != board2[y][x])
        sol++;
    }
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": ";
    cout << solve() << endl;
  }
}
