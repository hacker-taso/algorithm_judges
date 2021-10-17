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
#define MOD 1000000007
const string possible = "Possible";
const string impossible = "Impossible";
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int nr, nc;
int rsum, lsum;
vector<int> arr;
void init() {
  cin >> nr >> nc >> rsum >> lsum;
}

void printboard(vector<vector<int>>& board) {
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[0].size(); x++) {
      if (x != 0)
        cout << " ";
      cout << board[y][x];
    }
    cout << endl;
  }
}

void solve22(vector<vector<int>>& board) {
  board[0][0] += rsum;
  board[0][1] += lsum;
  printboard(board);
}

void solve() {
  rsum -= nr+nc-1; lsum -= nr+nc-1;
  if (rsum < 0 || lsum < 0) {
    cout << impossible << endl;
    return;
  }

  vector<vector<int>> board = vector<vector<int>>(nr, vector<int>(nc, 1));
  cout << possible << endl;
  if (nr == 2 && nc == 2) {
    solve22(board);
    return;
  }
  int minv = min(lsum, rsum);
  if (nr == 2) {
    for (int x=1; x<nc-1; x++)
      board[1][x] = 999;
    board[0][1] += minv;
    lsum -= minv;
    rsum -= minv;
    if (0 < lsum)
      board[1][0] += lsum; // lb
    else if (0 < rsum)
      board[1][nc-1] += rsum; // rb
  } else {
    for (int y=1; y<nr-1; y++)
      for (int x=1; x<nc; x++)
        board[y][x] = 999;
    board[1][0] += minv;
    lsum -= minv;
    rsum -= minv;
    if (0 < lsum)
      board[0][nc-1] += lsum; // rt
    else
      board[nr-1][nc-1] += rsum; // rb
  }
  printboard(board);
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
