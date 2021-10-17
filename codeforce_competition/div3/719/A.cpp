#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
using namespace std;
#define LT 0
#define RT 1
#define UP 2
#define DW 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
string s;
void init() {
}

bool solve() {
  vector<bool> visited(256, 0);
  visited[s[0]] = true;
  for (int i=1; i<s.size(); i++) {
    if (visited[s[i]] && s[i-1] != s[i])
      return false;
    visited[s[i]] = true;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, n;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cin >> n;
    cin >> s;
    if (solve()) {
      cout << "YES" <<endl;
    } else {
      cout << "NO" <<endl;
    }
  }
}
