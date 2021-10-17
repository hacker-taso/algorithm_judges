/*
입력:
4 5
c.xc
....
xx..
...x
x..x

출력:
1
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> board;
int width, height;

void solve() {
  dp[0][0] = board[0][0];
  for (int x=1; x<width; x++)
    dp[0][x] = dp[0][x-1] + board[0][x];
  for (int y=1; y<height; y++)
    dp[y][0] = dp[y-1][0] + board[y][0];
  for (int y=1; y<height; y++) {
    for (int x=1; x<width; x++) {
      dp[y][x] = max(dp[y-1][x], dp[y][x-1]) + board[y][x];
    }
  }
}

int main() {
  cin >> width >> height;
  board = vector<vector<int>>(height);
  for (int y=0; y<height; y++) {
    board[y] = vector<int>(width);
    for (int x=0; x<width; x++)
      cin >> board[y][x];
  }
  dp = vector<vector<int>>(height);
  for (int i=0; i<height; i++)
    dp[i] = vector<int>(width, 0);
  solve();
  cout << dp[height-1][width-1] << endl;
  return 0;
}
