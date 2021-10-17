#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<algorithm>
#include<cmath>
using namespace std;
int n;

string solve() {
  if (n%2 != 0) return "NO";
  int sq = (int)(sqrt(n/2)+0.0001);
  if (sq*sq*2 == n) return "YES";
  if (n%4 != 0) return "NO";
  sq = (int)(sqrt(n/4)+0.0001);
  if (sq*sq*4 == n) return "YES";
  return "NO";
}

int main() {
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n;
    cout << solve() << endl;
  }
}
