// submit other file.
#include<iostream>
#include<vector>
using namespace std;
int r, b, d;

bool solve() {
  int M = max(r, b);
  int m = min(r, b);
  int maxDiff = M/m + (0<(M%m)) - 1;
  return maxDiff <= d;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> r >> b >> d;
    if (solve()) {
      cout << "YES" <<endl;
    } else {
      cout << "NO" <<endl;
    }
  }
}