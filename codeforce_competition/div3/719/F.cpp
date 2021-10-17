#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
using namespace std;
#define LT 0
#define RT 1
#define UP 2
#define DW 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int n, k;
int T;
string s;
void init() {
  cin >> n >> T;
  cin >> k;
}

void solve() {
  int lo = 0, hi = n-1;
  int onecnt;
  int cnt = 0;
  while (lo <= hi) {
    int mid = (lo+hi)/2;
    cout << "? 1 " << mid+1 <<endl;
    cin >> onecnt;
    if (onecnt == -1)
      return;
    int totcnt = mid+1;
    int zerocnt = totcnt - onecnt;
    if (zerocnt < k) {
      lo = mid+1;
    } else if (k <= zerocnt) {
      hi = mid;
    }
  }
  cout << "! " << hi+1 <<endl;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
