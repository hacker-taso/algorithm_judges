#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> arr;
void solve() {
  for (int i=0; i<arr.size(); i++) {
    bool sqr = false;
    for (int j=1; j<=sqrt(arr[i])+1; j++) {
      if (j*j == arr[i]) {
        sqr = true;
        break;
      }
    }
    if (!sqr) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" <<endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int T, n;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n;
    arr.resize(n);
    for (int j=0; j<n; j++)
      cin >> arr[j];
    solve();
  }
}
