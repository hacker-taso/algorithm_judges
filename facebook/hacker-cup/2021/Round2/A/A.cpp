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

// what if no underneath condition? -> count differenct outfits between rounds.
void solve() {
  unordered_map<int, int> remains;
  map<int, int> beforecnts;
  map<int, int> curcnts;
  for (int i=0; i<nmodel; i++) {
    remains[shows[0][i]]++;
    beforecnts[shows[0][i]]++;
  }
  int totaldiff = 0;
  int totalused = 0;
  for (int i=1; i<nround+1; i++) {
    curcnts.clear();
    for (int j=0; j<nmodel; j++)
      curcnts[shows[i][j]]++;
    int diff = 0;
    for (auto it = beforecnts.begin(); it != beforecnts.end(); it++) {
      int outfit = it->first;
      int beforecnt = it->second;
      int curcnt = 0;
      if (curcnts.find(outfit) != curcnts.end())
        curcnt = curcnts[outfit];
      int changed = beforecnt - curcnt;
      if (0 < changed)
        diff += changed;
      auto remainit = remains.find(outfit);
      if (0 < changed && remainit != remains.end()) {
        int used = min(changed, remainit->second);
        remainit->second -= used;
        if (0 == remainit->second)
          remains.erase(outfit);
        totalused += used;
      }
    }
    totaldiff += diff;
    beforecnts = curcnts;
  }
  cout << totaldiff - totalused << endl;
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
