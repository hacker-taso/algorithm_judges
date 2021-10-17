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
int N, s;
vector<int> arr;
void init() {
  cin >> N;
  arr.resize(N);
  for (int i=0; i<N; i++)
    cin >> arr[i];
  cin >> s;
}

void solve() {
  for (int i=0; i<arr.size(); i++) {
    int bidx = i;
    for (int j=i+1; j<arr.size() && j-i<=s; j++) {
      if (arr[bidx] < arr[j])
        bidx = j;
    }
    int tmp = arr[bidx];
    for (int j=bidx; i<j; j--) {
      arr[j] = arr[j-1];
    }
    arr[i] = tmp;
    s -= bidx-i;
  }
  for (int i=0; i<arr.size(); i++) {
    cout << arr[i];
    if (i+1 != arr.size())
      cout << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
