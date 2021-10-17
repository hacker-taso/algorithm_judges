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
int n;
void init() {
  cin >> n;
}

int solve() {
  int cipher = 0;
  int tmp = n;
  while (tmp) {
    tmp /= 10;
    cipher++;
  }
  tmp = 1;
  for (int i=1; i<cipher; i++) {
    tmp *= 10;
  }
  int msig = n/tmp;
  tmp = msig;
  for (int i=1; i<cipher; i++) {
    tmp = tmp*10 + msig;
  }
  int sol = (cipher-1)*9 + (msig-1) + (tmp <= n);
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
