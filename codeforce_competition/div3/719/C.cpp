#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
using namespace std;
#define LT 0
#define RT 1
#define UP 2
#define DW 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int n;
int board[100][100];
void init() {
  cin >> n;
  board[0][0] = 2;
  board[0][1] = 9;
  board[0][2] = 7;
  board[1][0] = 4;
  board[1][1] = 6;
  board[1][2] = 3;
  board[2][0] = 1;
  board[2][1] = 8;
  board[2][2] = 5;
}

void construct() {
  for (int cn=3; cn<n; cn++) {
    int small = (cn)*(cn)+1;
    int big = (cn+1)*(cn+1);
    bool turn = true;
    for (int y=0; y<=cn; y++) {
      if (turn) board[y][cn] = small++;
      else board[y][cn] = big--;
      turn = !turn;
    }
    for (int x=cn-1; 0<=x; x--) {
      if (turn) board[cn][x] = small++;
      else board[cn][x] = big--;
      turn = !turn;
    }
    swap(board[cn][0], board[1][cn]);
  }
}

void solve() {
  if (n==1) {
    cout << 1 <<endl;
    return;
  }
  if (n==2) {
    cout << -1 <<endl;
    return;
  }
  construct();
  for (int y=0; y<n; y++) {
    for (int x=0; x<n; x++) {
      cout << board[y][x] << " ";
    }
    cout <<endl;
  }
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
