#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N;
vector<int> students;
int likes[401][4];
int board[20][20];
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int isValid(int y, int x) {
  return 0<=y && y<N && 0<=x && x<N;
}

int score(int st, int y, int x) {
  int ret = 0;
  for (int i=0; i<4; i++) {
    int curY = y+dy[i]; int curX = x+dx[i];
    if (!isValid(curY, curX)) continue;
    int you = board[curY][curX];
    if (you == 0) {
      ret += 10;
      continue;
    }
    for (int j=0; j<4; j++) {
      if (likes[st][j] == you) ret += 100;
    }
  }
  return ret;
}

int pref(int y, int x) {
  int cnt = 0;
  int me = board[y][x];
  for (int i=0; i<4; i++) {
    int curY = y+dy[i]; int curX = x+dx[i];
    if (!isValid(curY, curX)) continue;
    int you = board[curY][curX];
    for (int j=0; j<4; j++) {
      cnt += (likes[me][j] == you);
    }
  }
  if (cnt == 1) return 1;
  else if (cnt == 2) return 10;
  else if (cnt == 3) return 100;
  else if (cnt == 4) return 1000;
  return 0;
}

int solve() {
  for (int st: students) {
    int maxV = -1; int opY; int opX;
    for (int y=0; y<N; y++) {
      for (int x=0; x<N; x++) {
        if (board[y][x] != 0) continue;
        int curScore = score(st, y, x);
        if (maxV < curScore) {
          maxV = curScore;
          opY = y;
          opX = x;
        }
      }
    }
    board[opY][opX] = st;
  }
  int ret = 0;
  for (int y=0; y<N; y++) {
    for (int x=0; x<N; x++) {
      ret += pref(y, x);
    }
  }
  return ret;
}

int main() {
  int tmp;
  memset(board, 0, sizeof(board));
  cin >> N;
  for (int i=0; i<N*N; i++) {
    cin >> tmp;
    students.push_back(tmp);
    for (int j=0; j<4; j++)
      cin >> likes[tmp][j];
  }
  cout << solve() <<endl;
}
