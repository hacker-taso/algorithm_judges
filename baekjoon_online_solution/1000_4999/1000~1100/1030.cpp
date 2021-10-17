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
int s, N, K, R1, R2, C1, C2;
void init() {
  cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
}
struct snapshot {
  int s, r1, r2, c1, c2;
};

void solve() {
  vector<snapshot> snapshots;
  int tmps = s, r1 = R1, r2 = R2, c1 = C1, c2 = C2;
  while (0 <= tmps) {
    snapshots.push_back({tmps, r1, r2, c1, c2});
    tmps--; r1 /= N; r2 /= N; c1 /= N; c2 /= N;
  }

  int xminus = 0, yminus = 0;
  vector<vector<int>> board = {{0}};
  for (int i=snapshots.size()-1; 0<=i; i--) {
    auto [s, r1, r2, c1, c2] = snapshots[i];
    int nr1 = r1-yminus, nr2 = r2-yminus;
    int nc1 = c1-xminus, nc2 = c2-xminus;
    if (i == 0) {
      for (int y=nr1; y<=nr2; y++) {
        for (int x=nc1; x<=nc2; x++) {
          cout << board[y][x];
        }
        cout << endl;
      }
      break;
    }
    vector<vector<int>> nboard((r2-r1+1)*N, vector<int>((c2-c1+1)*N, -1));
    for (int y=nr1; y<=nr2; y++) {
      for (int x=nc1; x<=nc2; x++) {
        for (int i=0; i<N; i++) {
          for (int j=0; j<N; j++) {
            nboard[(y-nr1)*N+i][(x-nc1)*N+j] = board[y][x];
          }
        }
        if (board[y][x] == 0) {
          for (int i=0; i<K; i++) {
            for (int j=0; j<K; j++) {
              nboard[(y-nr1)*N + (N-K)/2 + i][(x-nc1)*N + (N-K)/2 + j] = 1;
            }
          }
        }
      }
    }
    board = nboard;
    xminus = (xminus+nc1)*N;
    yminus = (yminus+nr1)*N;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
