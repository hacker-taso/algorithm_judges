/*
입력:
4
1110
1110
0110
0000

출력:
total: 11
size[1]: 8
size[2]: 3
*/

#include <iostream>
#include <vector>
#define Y 0
#define X 1
using namespace std;
int N, total;
vector<string> board;
vector<vector<int>> axes[51]; // y,x list
bool solveLen(int len);

void init() {
  for (int i=0; i<51; i++)
    axes[i] = vector<vector<int>>();
}
void solve() {
  total = 0;
  init();
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[y].size(); x++) {
      if (board[y][x] == '1') {
        total++;
        axes[1].push_back(vector<int>{y, x});
      }
    }
  }
  for (int i=2; i<51; i++) {
    if (!solveLen(i))
      return;
  }
}
bool solveLen(int len) {
  bool updated = false;
  for (int i=0; i < axes[len-1].size(); i++) {
    bool allOne = true;
    int ltY = axes[len-1][i][Y], ltX = axes[len-1][i][X];
    int newY = ltY + len - 1, newX = ltX + len - 1;
    if (N <= newY || N <= newX)
      continue;
    for (int y=ltY; y<=newY; y++) {
      if (board[y][newX] == '0') {
        allOne = false;
        break;
      }
    }
    for (int x=ltX; x<=newX; x++) {
      if (board[newY][x] == '0') {
        allOne = false;
        break;
      }
    }
    if (allOne) {
      axes[len].push_back(vector<int>{ltY, ltX});
      updated = true;
      total++;
    }
  }
  return updated;
}

int main() {
  cin >> N;
  board = vector<string>(N);
  for (int i=0; i<N; i++) {
    cin >> board[i];
  }
  solve();
  cout << "total: " << total << endl;
  for (int i=1; i<51; i++) {
    if (axes[i].size() == 0)
      return 0;
    cout << "size[" << i << "]: " << axes[i].size() << endl;
  }
  return 0;
}
