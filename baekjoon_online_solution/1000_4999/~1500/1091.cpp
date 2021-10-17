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
vector<int> S;
vector<int> P;
void init() {
  cin >> N;
  S.resize(N);
  P.resize(N);
  for (int i=0; i<N; i++)
    cin >> P[i];
  for (int j=0; j<N; j++)
    cin >> S[j];
}

map<vector<int>, bool> checked;

int solve() {
  vector<int> arr;
  for (int i=0; i<N; i++)
    arr.push_back(i%3);
  int cnt = 0;
  while (true) {
    if (arr == P)
      return cnt;
    if (checked[arr]) return -1;
    checked[arr] = true;
    vector<int> arr2(arr.size());
    for (int i=0; i<N; i++) {
      arr2[S[i]] = arr[i];
    }
    cnt++;
    arr = arr2;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() <<endl;
}
