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
#define MAX 1001
using namespace std;
int m[MAX];
int N;

void dfs(int cursum, int curn, int curcnt) {
  int i=2;
  while (true) {
    int n = curn*i;
    int sum = cursum + n;
    if (MAX<=sum)
      break;
    m[sum] = max(m[sum], curcnt+1);
    dfs(sum, n, curcnt+1);
    i++;
  }
}

void allInit() {
  memset(m, sizeof(m), 0);
  for (int i=3; i<MAX; i++) {
    m[i] = max(m[i], 1);
    dfs(i, i, 1);
  }
}
void init() {
  cin >> N;
}

int solve() {
  return m[N];
}

int main() {
  ios_base::sync_with_stdio(false);
  allInit();
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": ";
    cout << solve() << endl;
  }
}
