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
  int sol = 0;
  for (int i=0; i<N; i++) {
    int cnt = 0;
    double maxslope = -1000000000;
    for (int j=i-1; 0<=j; j--) {
      double curslope = (double)(arr[j]-arr[i])/(i-j);
      if (maxslope+1e-7 < curslope) {
        cnt++;
        maxslope = curslope;
      }
    }
    maxslope = -1000000000;
    for (int j=i+1; j<N; j++) {
      double curslope = (double)(arr[i]-arr[j])/(i-j);
      if (maxslope+1e-7 < curslope) {
        cnt++;
        maxslope = curslope;
      }
    }
    sol = max(sol, cnt);
  }
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
