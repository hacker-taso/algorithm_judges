#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
#include<map>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N, M;
vector<int> arr;
vector<int> arr2;
void init() {
  cin >> N >> M;
  arr.resize(M);
  for (int i=0; i<M; i++)
    cin >> arr[i];
  for (int i=0; i<10; i++)
    if (find(arr.begin(), arr.end(), i) == arr.end())
      arr2.push_back(i);
}

int sol;

void dfs(int curNum, int digit, int pushcnt) {
  if (digit == 1000000)
    return;
  for (int n: arr2) {
    int cur2 = curNum + n*digit;
    sol = min(sol, abs(N - cur2)+pushcnt+1);
    dfs(cur2, digit*10, pushcnt+1);
  }
}

int solve() {
  sol = abs(N-100);
  dfs(0, 1, 0);
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() <<endl;
}
