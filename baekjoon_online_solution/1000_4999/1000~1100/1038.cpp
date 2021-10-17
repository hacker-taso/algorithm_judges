// mistake:
// 1. 100 (should not be considered decreasing)
// 2. 9876543210 (long long)
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N;
void init() {
  cin >> N;
}

long long solve() {
  vector<int> arr[10];
  vector<int> arr2[10];
  if (N<10)
    return N;
  if (1022 == N)
    return 9876543210ull;
  if (1021 < N)
    return -1;
  N -= 9;
  for (int i=0; i<10; i++)
    arr[i].push_back(i);
  for (int digit=10; true; digit*=10) {
    for (int i=1; i<10; i++) {
      for (int j=0; j<i; j++) {
          if (j==0 && digit != 10) continue;
        arr2[i].insert(arr2[i].end(), arr[j].begin(), arr[j].end());
      }
      for (int j=0; j<arr2[i].size(); j++)
        arr2[i][j] += digit*i;
      if (N <= arr2[i].size()) {
        return arr2[i][N-1];
      }
      N -= arr2[i].size();
    }
    for (int i=1; i<10; i++) {
        arr[i] = arr2[i];
        arr2[i].clear();
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() <<endl;
}
