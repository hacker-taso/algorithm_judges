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
string s;
void init() {
  cin >> s;
}

void solve() {
  vector<int> cnts(256, 0);
  for (int i=0; i<s.size(); i++)
    cnts[tolower(s[i])]++;
  int maxcnt = 0;
  char maxc = 'a';
  for (int c='a'; c<='z'; c++) {
    if (maxcnt < cnts[c]) {
      maxcnt = cnts[c];
      maxc = c;
    }
  }
  for (int c='a'; c<='z'; c++) {
    if (maxcnt == cnts[c] && c != maxc) {
      cout << "?" <<endl;
      return;
    }
  }
  cout << (char)toupper(maxc) <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
