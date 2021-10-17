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
char arr[25][25];
int N;

void init() {
  cin >> N;
  for (int i=0; i<N; i++)
    cin >> arr[i];
}

bool visited[25];
vector<int> yorder;
// O(N*N)
bool checkPossible(int yidx) {
  if (yidx == N) return true;
  int y = yorder[yidx];
  bool checked = false;
  for (int x=0; x<N; x++) {
    if (visited[x] || arr[y][x] == '0') continue;
    checked = true;
    visited[x] = true;
    if (!checkPossible(yidx+1))
      return false;
    visited[x] = false;
  }
  return checked;
}

pair<int,int> getPos(int idx) {
  return {idx/N, idx%N};
}

// NC(N/2) * O(N*N) * N!
bool dfs(int idx, int remaincnt) {
  if (remaincnt == 0) {
    yorder.resize(N);
    for (int i=0; i<yorder.size(); i++) yorder[i] = i;
    do {
      memset(visited, 0, sizeof(visited));
      if (!checkPossible(0))
        return false;
    } while(next_permutation(yorder.begin(), yorder.end()));
    return true;
  }
  for (int i=idx; i<N*N; i++) {
    auto [y,x] = getPos(i);
    if (arr[y][x] == '0') {
      if (dfs(i+1, remaincnt))
        return true;
      arr[y][x] = '1';
      if (dfs(i+1, remaincnt-1))
        return true;
      arr[y][x] = '0';
    }
  }
  return false;
}

// O(2^(N*N)) * O(N*N) * O(N*N) * N! = 2^16 * 4*4 * 4*4 * 4! (in max)
int solve() {
  for (int i=0; i<=N*N; i++) {
    if (dfs(0, i))
      return i;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": " << solve() << endl;
  }
}
