#include<iostream>
#include<algorithm>
using namespace std;
int N, R, P, S;

string solve() {
  string s;
  for (int i=0; i<P; i++)
    s += 'P';
  for (int i=0; i<R; i++)
    s += 'R';
  for (int i=0; i<S; i++)
    s += 'S';
  do {
    string s2 = s;
    while (s2.size() != 1) {
      string tmp;
      bool can = true;
      for (int i=0; i<s2.size(); i+=2) {
        if (s2[i] == s2[i+1]) {
          can = false;
          break;
        } else {
          if (s2[i] > s2[i+1]) swap(s2[i], s2[i+1]);
          if (s2[i] == 'R' && s2[i+1] == 'S') tmp += 'R';
          else if (s2[i] == 'P' && s2[i+1] == 'R') tmp += 'P';
          else if (s2[i] == 'P' && s2[i+1] == 'S') tmp += 'S';
        }
      }
      if (!can) break;
      s2 = tmp;
    } // O(2^n)
    if (s2.size() == 1)
      return s;
  } while(next_permutation(s.begin(), s.end())); // O((2^n)!)
  return "IMPOSSIBLE";
}

int main() {
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> R>> P >> S;
    cout << "Case #" << i << ": " << solve() << endl;
  }
}