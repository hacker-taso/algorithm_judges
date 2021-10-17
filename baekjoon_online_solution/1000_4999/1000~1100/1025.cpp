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
using namespace std;
int N, M;
vector<string> board;
void init() {
  cin >> N >> M;
  board.resize(N);
  for (int i=0; i<N; i++)
    cin >> board[i];
}

bool isValid(int y, int x) {
  return 0<=y && 0<=x && y<N && x<M;
}

int solve() {
  int sol = -1;
  for (int sy=0; sy<N; sy++) {
    for (int sx=0; sx<M; sx++) {
      for (int dy=-N; dy<=N; dy++) {
        for (int dx=-M; dx<=M; dx++) {
          if (dy == 0 && dx == 0)
            continue;
          string s;
          for (int y=sy, x=sx; isValid(y, x); y+=dy, x+=dx) {
            s += (char)board[y][x];
            int curv = stoi(s);
            int sq = (int)sqrt(curv+0.0001);
            if (sq*sq == curv) {
              sol = max(sol, curv);
            }
          }
        }
      }
    }
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() << endl;
}
