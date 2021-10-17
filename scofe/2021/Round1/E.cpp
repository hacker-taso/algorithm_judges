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
#include <cstdlib> 
#define INF 1234567890
#define START 'c'
#define NO 'x'
#define YES '.'
using namespace std;
vector<string> board;
int width, height;
vector<vector<int>> dp;

void initFirstRow() {
  for (int x=0; x<width; x++) {
    if (board[0][x] != START)
      continue;
    dp[0][x] = 0;
    for (int x2=x-1; 0<=x2; x2--) {
      if (board[0][x2] == NO || board[0][x2] == START)
        break;
      int dist = x - x2;
      dp[0][x2] = min(dp[0][x2], dist);
    }
    for (int x2=x+1; x2<width; x2++) {
      if (board[0][x2] == NO || board[0][x2] == START)
        break;
      int dist = x2 - x;
      dp[0][x2] = min(dp[0][x2], dist);
    }
  }
}
int solve() {
  initFirstRow();
  for (int y=1; y<height; y++) {
    int aboveY = y-1;
    for (int x=0; x<width; x++) {
      if (board[y][x] == NO)
        continue;
      dp[y][x] = dp[aboveY][x];
      for (int aboveX=x-1; 0<=aboveX; aboveX--) {
        if (board[y][aboveX] == NO)
          break;
        int dist = abs(x - aboveX);
        dp[y][x] = min(dp[y][x], dp[aboveY][aboveX] + dist);
      }
      for (int aboveX=x+1; aboveX<width; aboveX++) {
        if (board[y][aboveX] == NO)
          break;
        int dist = abs(x - aboveX);
        dp[y][x] = min(dp[y][x], dp[aboveY][aboveX] + dist);
      }
    }
  }
  int sol = INF;
  for (int x=0; x<width; x++)
    sol = min(sol, dp[height-1][x]);
  if (sol == INF)
    return -1;
  return sol;
}

int main() {
  cin >> width >> height;
  board = vector<string>(height);
  for (int y=0; y<height; y++) {
    cin >> board[y];
  }
  dp = vector<vector<int>>(height);
  for (int i=0; i<dp.size(); i++)
    dp[i] = vector<int>(width, INF);
  cout << solve() << endl;
  return 0;
}