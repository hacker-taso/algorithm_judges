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
int N, K;
struct rectangle {
  int x1, y1, x2, y2;
};
vector<rectangle> recs;
void init() {
  int x1, y1, x2, y2;
  cin >> N >> K;
  for (int i=0; i<N; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    recs.push_back({x1, y1, x2, y2});
  }
}

struct rec_comp {
  bool operator () (rectangle r1, rectangle r2) {
    return r1.y2 > r2.y2;
  }
};

void solve() {
  vector<int> sizes;
  for (int i=N-1; 0<=i; i--) {
    auto [sx1, sy1, sx2, sy2] = recs[i];
    int sz = 0;
    for (int x=sx1; x<sx2; x++) {// x axis right is area
      vector<rectangle> currecs;
      for (int j=i+1; j<=N-1; j++) {
        auto [tx1, ty1, tx2, ty2] = recs[j];
        if (tx1 <= x && x < tx2)
          currecs.push_back(recs[j]);
      }
      sort(currecs.begin(), currecs.end(), rec_comp());
      int yt = sy2, yb = sy1;
      for (int j=0; j<currecs.size(); j++) {
        auto [tx1, ty1, tx2, ty2] = currecs[j];
        if (ty2<=yb || yt <= ty1) continue;
        if (yt <= ty2) {
          yt = ty1;
          if (yt <= yb)
            break;
          continue;
        }
        sz += yt - ty2;
        yt = ty1;
        if (yt <= yb)
          break;
      }
      sz += max(yt-yb, 0);
    }
    sizes.push_back(sz);
  }
  reverse(sizes.begin(), sizes.end());
  priority_queue<pair<int,int>> pq;
  for (int i=0; i<N; i++)
    pq.push({sizes[i], -i});
  vector<int> idxs;
  while (!pq.empty() && 0<K) {
    auto [sz, i] = pq.top();
    pq.pop();
    idxs.push_back(-i + 1);
    K--;
  }
  sort(idxs.begin(), idxs.end());
  for (int i=0; i<idxs.size(); i++) {
    cout << idxs[i];
    if (i+1 != idxs.size())
      cout << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
