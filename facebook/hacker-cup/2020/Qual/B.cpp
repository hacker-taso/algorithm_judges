#include<iostream>
using namespace std;
int N;
string s;
bool solve() {
  int acnt = 0;
  int bcnt = 0;
  for (char c: s) {
    if (c=='A') acnt++;
    else bcnt++;
  }
  return !(3 <= acnt-bcnt || 3 <= bcnt-acnt);
}

int main() {
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    cin >> s;
    bool sol = solve();
    cout << "Case #" << i+1 << ": ";
    if (sol)
      cout << 'Y' << endl;
    else
      cout << 'N' << endl;
  }
}