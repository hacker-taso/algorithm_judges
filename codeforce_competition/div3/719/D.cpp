#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<unordered_map>
using namespace std;
#define LT 0
#define RT 1
#define UP 2
#define DW 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int n;
int arr[200000];
unordered_map<int, int> cnts;
bool neg[200000];
void init() {
  cin >> n;
  for (int j=0; j<n; j++)
    cin >> arr[j];
  cnts = unordered_map<int, int>();
}

long long solve() {
  long long sol = 0;
  for (int i=0; i<n; i++) {
    int cur = arr[i]-i;
    sol = sol + cnts[cur];
    cnts[cur] += 1;
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << solve() << endl;
  }
}
