#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<algorithm>
using namespace std;
int n, x;
vector<int> weights;

void solve() {
  sort(weights.begin(), weights.end());
  int sum = 0;
  for (int i=0; i<weights.size(); i++) {
    sum += weights[i];
    if (sum == x) {
      if (weights[i] == weights[weights.size()-1]) {
        cout << "NO" <<endl;
        return;
      } else {
        swap(weights[i], weights[weights.size()-1]);
      }
    }
  }
  cout << "YES" <<endl;
  for (int w: weights) {
    cout << w << " ";
  }
  cout <<endl;
}

int main() {
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n >> x;
    weights.resize(n);
    for (int j=0; j<n; j++)
      cin >> weights[j];
    solve();
  }
}
