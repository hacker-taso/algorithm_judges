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
#include<unordered_map>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int nround;
int nmodel;
vector<int> ioutfits;
vector<vector<int>> shows;
void init() {
  cin >> nround;
  cin >> nmodel;
  shows = vector<vector<int>>(nround+1, vector<int>(nmodel, 0));
  for (int i=0; i<nround+1; i++)
    for (int j=0; j<nmodel; j++)
      cin >> shows[i][j];
}

void solve() {
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << "Case #" << i << ": ";
    solve();
  }
}
