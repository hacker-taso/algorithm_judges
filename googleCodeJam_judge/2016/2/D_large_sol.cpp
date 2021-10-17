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
// dp[balanced_left_sum][stat] = {minSq, unused_stat};
unordered_map<long long, pair<int,long>> dp[26];
int N2;

int iterate() {
  for (int i=0; i<26; i++)
    dp.clear();
  N2 = compSets.size();
  queue<tuple<long long, long long, int>> q;
  q.push({0, 0, 0});
  while (!q.empty()) {
    auto bits = q.front();
    q.pop();
    for (int i=0; i<=25; i++) {
      auto [minSq, ubits] = dp[i].find(stat);
      for (int bs = ubits; bs!=0; bs) {
        
      }
    }
    int firstone;
    for(firstone=N2-1; 0<=firstone; firstone--)
      if ((bits>>i)&1 == 1) break;
    for (int i=firstone+1; i<N2; i++) {
      if ((i==0) || compSets[i - 1].l != compSets[i].l || compSets[i - 1].r != compSets[i].r
        || ((bits >> (i-1))&1 == 1)) {
        q.push(bits | (1ull << i));
      }
    }
  }
  return dp[N2][(1ull<<N2) - 1].first;
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
  int minSq = iterate();

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
