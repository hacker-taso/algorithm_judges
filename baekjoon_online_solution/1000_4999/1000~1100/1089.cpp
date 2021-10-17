#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
#include<cmath>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N;
string table[5] = {
  "###...#.###.###.#.#.###.###.###.###.###",
  "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
  "#.#...#.###.###.###.###.###...#.###.###",
  "#.#...#.#.....#...#...#.#.#...#.#.#...#",
  "###...#.###.###...#.###.###...#.###.###"
};
vector<string> board;
void init() {
  cin >> N;
  board.resize(5);
  for (int i=0; i<5; i++)
    cin >> board[i];
}

vector<int> getPossible(int bx) {
  vector<int> possible;
  for (int i=0; i<=9; i++) {
    int tx=i*4;
    bool same = true;
    for (int y=0; y<5; y++) {
      for (int dx=0; dx<3; dx++) {
        if (board[y][bx+dx] == '#' && table[y][tx+dx] == board[y][bx+dx])
          continue;
        if (board[y][bx+dx] == '.')
          continue;
        same = false;
      }
    }
    if (same)
      possible.push_back(i);
  }
  return possible;
}

void solve() {
  double res = 0;
  for (int i=0; i<N; i++) {
    vector<int> cur = getPossible(i*4);
    if (cur.size() == 0) {
      res = -1;
      break;
    }
    double s = accumulate(cur.begin(), cur.end(), 0);
    s /= cur.size();
    res += s * pow(10, N-1-i);
  }
  cout << fixed << setprecision(9) << res <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
