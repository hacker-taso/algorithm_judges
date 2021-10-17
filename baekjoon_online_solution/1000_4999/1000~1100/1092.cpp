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
int ncrain, nbox;
vector<int> crains;
vector<int> boxes;
void init() {
  cin >> ncrain;
  crains.resize(ncrain);
  for (int i=0; i<ncrain; i++)
    cin >> crains[i];
  cin >> nbox;
  boxes.resize(nbox);
  for (int i=0; i<nbox; i++)
    cin >> boxes[i];
}

int solve() {
  sort(crains.begin(), crains.end(), greater<int>());
  sort(boxes.begin(), boxes.end(), greater<int>());
  vector<int> cursors(ncrain, 0);
  int cnt = 0;
  while (true) {
    cnt++;
    for (int i=0; i<ncrain; i++) {
      for (; cursors[i] < nbox; cursors[i]++) {
        if (boxes[cursors[i]] == -1) continue;
        if (crains[i] < boxes[cursors[i]] && i == 0)
          return -1;
        if (crains[i] < boxes[cursors[i]]) continue;
        boxes[cursors[i]] = -1;
        break;
      }
    }
    if (cursors[0] == nbox)
      return cnt-1;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() <<endl;
}
