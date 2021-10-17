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
int N, M;
bool knowlie[51];
bool parties[51][51];
bool trueparties[51];
void init() {
  memset(trueparties, 0, sizeof(trueparties));
  memset(parties, 0, sizeof(parties));
  memset(knowlie, 0, sizeof(knowlie));
  int tmp, tmp2;
  cin >> N >> M;
  cin >> tmp;
  for (int i=0; i<tmp; i++) {
    cin >> tmp2;
    knowlie[tmp2] = true;
  }
  for (int i=0; i<M; i++) {
    cin >> tmp;
    for (int j=0; j<tmp; j++) {
      cin >> tmp2;
      parties[i+1][tmp2] = true;
    }
  }
}

void solve() {
  int notruecnt = 0;
  while (true) {
    notruecnt = 0;
    bool updated = false;
    for (int i=1; i<=M; i++) {
      if (trueparties[i]) continue;
      for (int j=1; j<=N; j++) {
        if (parties[i][j] && knowlie[j]) {
          trueparties[i] = true;
          updated = true;
        }
      }
      if(trueparties[i]) {
        for (int j=1; j<=N; j++) {
          if (parties[i][j]) {
            knowlie[j] = true;
          }
        }
      }
      notruecnt++;
    }
    if (!updated)
      break;
  }
  cout << notruecnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
