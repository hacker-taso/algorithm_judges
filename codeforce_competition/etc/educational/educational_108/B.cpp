#include<iostream>
#include<vector>
using namespace std;
int n, m, k;

bool solve() {
  return n*m-1 == k;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n >> m >> k;
    if (solve()) {
      cout << "YES" <<endl;
    } else {
      cout << "NO" <<endl;
    }
  }
}