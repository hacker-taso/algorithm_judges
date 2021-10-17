// pattern:
// 1.pre ~ (ex. 2020->2021)
// 2.pre+1 ~ (ex. 6999 -> 7071)
// 3.1~ (9990 -> 12345, 99199 -> 100101)
// # 4.9~ or [90,99]~, [990, 999]~, ... (ex. 9999999999 (10자리수) -> 96979899100(11자리수))
// It seems that pattern 4 doesn't exist.
// mistake: there was other pattern: 1762639527227-> 3456789101112
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<limits>
#define MAX_S "99999999999999999999999999999999999999"
using namespace std;
string s;

string solve() {
  string minS=MAX_S;
  // pattern 1 and 2
  for (int i=1; i<=(s.size()+1)/2; i++) {
    long long pre = stoll(s.substr(0, i));
    for (long long j=pre; j<=pre+1; j++) {
      long long it = j;
      string curS;
      while (curS.size() < s.size()) {
        curS += to_string(it++);
      }
      if (curS.size() == s.size() && s < curS)
        minS = min(minS, curS);
    }
  }
  // pattern 3
  string minS2 = "99999999999999999999999999999999";
  for (long long i=1; to_string(i).size()<=(s.size()+1)/2+1; i*=10) {
    long long it = i;
    string curS;
    while (curS.size() < s.size()+1) {
      curS += to_string(it++);
    }
    if (curS.size() == s.size()+1)
      minS2 = min(minS2, curS);
  }
  // pattern 4
  for (long long i=10; to_string(i-1).size() <=(s.size()+1)/2; i*=10) {
    for (long long j=i-1; 5<j && i-10<=j; j--) {
      long long it = j;
      string curS;
      while (curS.size() < s.size()) {
        curS += to_string(it++);
      }
      if (curS.size() == s.size() && s < curS)
        minS = min(minS, curS);
    }
  }
  if (minS == MAX_S) return minS2;
  return minS;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> s;
    cout << "Case #" << i << ": " << solve() <<endl;
  }
}
