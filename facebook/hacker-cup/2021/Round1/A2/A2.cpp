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
#define MOD 1000000007
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N;
string W;
void init() {
  cin >> N;
  cin >> W;
}

void solve() {
  int sol = 0;
  char cur = -1;
  int curcnt = 0;
  int curfcnt = 0;
  int sum = 0;
  int it = 0;
  for (char c: W) {
    if (cur == -1) {
      if (c == 'F') {
        curfcnt++;
      } else {
        cur = c;
        curcnt = 1 + curfcnt;
        curfcnt = 0;
      }
      continue;
    }

    if (c == 'F') { 
      sol = (sol+sum)%MOD;
      curfcnt++;
    } else if (c == cur) {
      sol = (sol+sum)%MOD;
      curcnt = curcnt + curfcnt + 1;
      curfcnt = 0;
    } else if (c != cur) {
      it += curcnt;
      sum = (sum+it)%MOD;
      sol = (sol+sum)%MOD;
      cur = c;
      curcnt = curfcnt + 1;
      curfcnt = 0;
    } else {
      cout << "something's wrong!" << endl;
      return;
    }
  }
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": ";
    solve();
  }
}
/*
OXFX

FXXFXFOOXF
1234567890
XXXXXXOOXX
1 start = 2 start ~ = 5 start = 1+1+2+2  (6*5 = 30. 6= 2(X)*2+1(O)*2)
6 start = 7 start = 8 start = 2 (2*3 = 6) (2 on behind)
9 start = 0 start = 0
0:5
1:3
2:2
5*2*1 = 10 (2)
2*3*1 + 5*2*2 = 26 (5,3)
36

1: 2*(1*5) = 10
2: 2*(2*5+3) = 26

XFOFXFOFXFOFX
1234567890ABC
0_1 2 3 4 5 6

0:1
1:2
2:2
3:2
4:2
5:2
6:1
1: 2*(1) 
2: 2*(2+1*2) (add 1+2)
3: 2*(3+2*2+1*2) (add 1+2+2)
4: 2*(4+3*2+2*2+1*2) (add 1+2+2+2)
5: 2*(5+4*2+3*2+2*2+1*2) (add 1+2+2+2+2)
6: 1*(6+5*2+4*2+3*2+2*2+1*2) (add 1+2+2+2+2+2)

x: n*(S + I)
I = cnt until now.

*/