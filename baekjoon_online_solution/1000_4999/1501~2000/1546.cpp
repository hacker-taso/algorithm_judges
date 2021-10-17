#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
#include<map>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N;
vector<int> arr;
void init() {
  cin >> N;
  arr.resize(N);
  for (int i=0; i<N; i++)
    cin >> arr[i];
}

void solve() {
  int maxv = *max_element(arr.begin(), arr.end());
  int sum = accumulate(arr.begin(), arr.end(), 0);
  double res = (double)sum/maxv * 100/arr.size();
  cout << fixed << setprecision(9) << res <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
