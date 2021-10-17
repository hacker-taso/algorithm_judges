// I've read the solution.
// mistake: using map.insert for replacing. It doesn't replace. Instead use [].
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<unordered_map>
#include<map>
#include<numeric>
#include<string>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
char arr[25][25];
int N;

#include <functional>
#include <string>
#include <utility>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};


void init() {
  cin >> N;
  string tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    for (int j = 0; j < N; j++)
      arr[i][j] = tmp[j] - '0';
  }
}

vector<int> comp[2];
bool visited[2][25];
void fillConnected(bool isRight, int cur) {
  if (visited[isRight][cur]) return;
  visited[isRight][cur] = true;
  comp[isRight].push_back(cur);
  int dx = 0, dy = 1;
  int fx = cur, fy = 0;
  if (!isRight) {
    swap(dx, dy);
    swap(fx, fy);
  }
  for (int y = fy, x = fx; x < N && y < N; x += dx, y += dy) {
    if (arr[y][x]) {
      fillConnected(!isRight, isRight ? y : x);
    }
  }
}

struct compSet {
  int l, r;
};
vector<compSet> compSets;
vector<int> setCnts;
unordered_map<long long, int> dp;
unordered_map<pair<long long, long long>, int, pair_hash> dp2;
map<long long, vector<pair<int, long long>>> dp3;
struct stat2 {
  long long bbits, ubits;
  int minSq;
};
int N2;

// This one is too slow.
void check(long long ubits, vector<pair<int, long long>>& res) {
  auto it = dp3.find(ubits);
  if (it != dp3.end()) {
    res = it->second;
    return;
  }
  for (long long bs = ubits; bs != 0; bs = ubits & (bs - 1)) {
    auto it = dp.find(bs);
    if (it == dp.end()) {
      int lsum = 0, rsum = 0;
      for (int i = 0; i < N2; i++) {
        if ((bs >> i) & 1 == 1) {
          lsum += compSets[i].l, rsum += compSets[i].r;
        }
      }
      int res2 = -1;
      if (lsum == rsum)
        res2 = lsum * lsum;
      dp[bs] = res2;
      if (res2 != -1) {
        res.push_back({res2, bs});
      }
    }
    else if (it->second == -1) {
      continue;
    }
    else {
      res.push_back({it->second, bs});
    }
  }
  dp3.insert({ubits, res});
}

// Y=null ~ all, t= 0 ~ sum(Y)
int bfs() {
  N2 = compSets.size();
  dp.clear();
  dp2.clear();
  dp3.clear();
  queue<stat2> q;
  q.push({ 0, 0, 0 });
  dp2.insert({ {0, 0}, 0 });
  while (!q.empty()) {
    auto[bbits, ubits, minSq] = q.front();
    q.pop();
    long long allbits = bbits | ubits;
    auto it = dp2.find({ bbits, ubits });
    if (it->second < minSq)
      continue;
    if (bbits == ((1ull << N2) - 1)) {
      return minSq;
    }
    for (int i = 0; i < N2; i++) {
      if (((allbits >> i) & 1) == 0
        && ((i == 0) || (compSets[i - 1].l != compSets[i].l || compSets[i - 1].r != compSets[i].r)
          || ((allbits >> (i - 1)) & 1 == 1))) {
        long long ubits2 = ubits | (1ull << i);
        long long allbits2 = bbits | ubits2;
        vector<pair<int, long long>> res;
        check(ubits2, res);
        if (0 < res.size()) {
          for (int j = 0; j < res.size(); j++) {
            auto it = dp2.find({ bbits | res[j].second, ubits2 ^ res[j].second });
            if (it == dp2.end() || minSq + res[j].first < it->second) {
              q.push({ bbits | res[j].second, ubits2 ^ res[j].second, minSq + res[j].first });
              dp2[{bbits | res[j].second, ubits2 ^ res[j].second}] = minSq + res[j].first;
            }
          }
        }
        else {
          auto it = dp2.find({ bbits, ubits2 });
          if (it == dp2.end() || minSq < it->second) {
            q.push({ bbits, ubits2, minSq });
            dp2[{bbits, ubits2}] = minSq;
          }
        }
      }
    }
  }
  return 0;
}

int compCnts[26][26];
int solve() {
  memset(visited, 0, sizeof(visited));
  memset(compCnts, 0, sizeof(compCnts));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        for (int k = 0; k < 2; k++)
          comp[k].clear();
        fillConnected(i, j);
        compCnts[comp[0].size()][comp[1].size()]++;
      }
    }
  }
  compSets.clear();
  for (int y = 0; y < 26; y++) {
    for (int x = 0; x < 26; x++) {
      for (int i = 0; i < compCnts[y][x]; i++)
        compSets.push_back({ y, x });
    }
  }
  int minSq = bfs();

  int orig = 0;
  for (int y = 0; y < N; y++)
    for (int x = 0; x < N; x++)
      orig += arr[y][x];
  int sol = minSq - orig;
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    init();
    cout << "Case #" << i << ": " << solve() << endl;
  }
}
