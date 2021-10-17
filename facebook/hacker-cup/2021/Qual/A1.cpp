#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
string s;
vector<char> vowels = {'A', 'E', 'I', 'O', 'U'};
#define showthis(s) cout << s << endl;

int solve() {
  vector<int> cnts(256, 0);
  for (char c: s) {
    cnts[c]++;
  }
  int vcnt = 0;
  char vmax = 'A';
  char cmax = 'B';
  for (char c='A'; c<='Z'; c++) {
    bool isv = find(vowels.begin(), vowels.end(), c) != vowels.end();
    vcnt += isv ? cnts[c] : 0;
    if (isv && cnts[vmax] < cnts[c]) {
      vmax = c;
    } else if (!isv && cnts[cmax] < cnts[c]) {
      cmax = c;
    }
  }

  // change vs into c
  int twice = s.size() - cnts[cmax] - vcnt;
  int once = vcnt;
  int ret = twice*2 + once;
  showthis(ret)
  // change cs into v
  twice = vcnt - cnts[vmax];
  once = s.size() - vcnt;
  ret = min(ret, twice*2 + once);
  showthis(ret)
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> s;
    cout << "Case #" << i+1 << ": " << solve() << endl;
  }
}
