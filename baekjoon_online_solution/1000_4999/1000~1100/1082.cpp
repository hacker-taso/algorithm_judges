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
int N, money;
vector<int> arr;
void init() {
  cin >> N;
  arr.resize(N);
  for (int i=0; i<N; i++)
    cin >> arr[i];
  cin >> money;
}

void solve() {
  vector<int> num;
  int cheaps[2] = {51, 51};
  int cidx[2] = {0, 0};
  for (int i=0; i<arr.size(); i++) {
    if (arr[i] <= cheaps[0]) {
      cheaps[1] = cheaps[0];
      cidx[1] = cidx[0];
      cheaps[0] = arr[i];
      cidx[0] = i;
    } else if (arr[i] <= cheaps[1]) {
      cheaps[1] = arr[i];
      cidx[1] = i;
    }
  }
  if (cidx[0] == 0) {
    if (money < cheaps[1]) {
      cout << 0 << endl;
      return;
    } else {
      num.push_back(cidx[1]);
      money -= cheaps[1];
    }
  } else {
    num.push_back(cidx[0]);
    money -= cheaps[0];
  }
  while (0<=money - cheaps[0]) {
    money -= cheaps[0];
    num.push_back(cidx[0]);
  }
  for (int i=0; i<num.size(); i++) {
    for (int j=N-1; num[i]<j; j--) {
      if (arr[j]-arr[num[i]] <= money) {
        money -= arr[j] - arr[num[i]];
        num[i] = j;
        break;
      }
    }
  }
  for (int i=0; i<num.size(); i++)
    cout << num[i];
  cout <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
