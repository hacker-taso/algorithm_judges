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
int r1, c1, r2, c2;
void init() {
  cin >> r1 >> c1 >> r2 >> c2;
}

int maxVal = 0;
void fillArr(vector<int>& arr, int c) {
  int first = 100020001 + (c-5000);
  int r = 5000;
  int dr = -1;
  int n=first;
  bool linear = false;
  bool v2= false;
  int dn = -1;
  bool firstiter = true;
  for (int i=0; i<2; i++) {
    for (; 0<=r && r<=5000; r += dr) {
      if (firstiter || r != 0)
        arr.push_back(n);
      if (0 < c) {
        if (abs(c) == r+1 && !linear) {
          linear = true;
          dn = 1;
        } else if (abs(c) == r && linear) {
          linear = false;
          v2 = true;
        }
      } else if (c < 0) {
        if (abs(c) == r && !linear) {
          linear = true;
          dn = -1;
        } else if (abs(c) == r && linear) {
          linear = false;
          dn = 1;
          v2 = true;
        }
      } else if (c==0 && !firstiter && r==0) {
        v2 = true;
        dn = 1;
      }
      if (r==0 && firstiter)
        break;
      if (linear) {
        n = n + dn;
      } else {
        n = n + dn*(-1+4*v2+8*r);
      }
    }
    r = 0;
    dr = 1;
    firstiter = false;
  }
  reverse(arr.begin(), arr.end());
}

void solve() {
  vector<int> arrs[5];
  for (int i=c1; i<=c2; i++) {
    fillArr(arrs[i-c1], i);
  }
  for (int i=5000+r1; i<=5000+r2; i++) {
    for (int j=0; j<=c2-c1; j++) {
      maxVal = max(arrs[j][i], maxVal);
    }
  }
  int w = to_string(maxVal).size();
  for (int i=5000+r1; i<=5000+r2; i++) {
    for (int j=0; j<=c2-c1; j++) {
      cout << setfill(' ') << setw(w) << arrs[j][i];
      if (j!=c2-c1)
        cout << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
