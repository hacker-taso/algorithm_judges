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
int A, B;
void init() {
  cin >> A >> B;
}

void solve() {
  if (A < B)
    cout << "<" << endl;
  else if (A > B)
    cout << ">" << endl;
  else
    cout << "==" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
