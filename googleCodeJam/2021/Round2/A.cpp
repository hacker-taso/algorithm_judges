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
using namespace std;
int N;
void solve() {
  int minpos, tmp;
  for (int i=N; 1<i; i--) {
    cout << "M " << N-i+1 << " " << N << endl;
    cin >> minpos;
    if (minpos == N-i+1)
      continue;
    cout << "S " << N-i+1 << " " << minpos << endl;
    cin >> tmp;
  }
  cout << "D" << endl;
  cin >> tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T >> N;
  for (int i=1; i<=T; i++) {
    solve();
  }
}
