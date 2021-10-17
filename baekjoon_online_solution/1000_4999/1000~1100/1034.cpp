#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int R, C, K;
int arr[50][50];
void init() {
  string tmp;
  cin >> R >> C;
  for (int y=0; y<R; y++) {
    cin >> tmp;
    for (int x=0; x<C; x++)
      arr[y][x] = tmp[x]-'0';
  }
  cin >> K;
}

int solve() {
  int sol = 0;
  for (int y=0; y<R; y++) {
    int onecnt = accumulate(arr[y], arr[y]+C, 0);
    int zerocnt = C - onecnt;
    if (K < zerocnt) continue;
    if (zerocnt%2 != K%2) continue;
    int samecnt = 0;
    for (int y2=y+1; y2<R; y2++) {
      bool same = true;
      for (int x=0; x<C; x++) {
        if (arr[y][x] != arr[y2][x]) {
          same = false;
          break;
        }
      }
      if (same) samecnt++;
    }
    sol = max(sol, samecnt+1);
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout <<solve() <<endl;
}
