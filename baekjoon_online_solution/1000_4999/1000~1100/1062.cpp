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
vector<string> arr;
bool wordmap[50][26];
int wordcnt[50];
int skip[] = {'a','n','t','i','c'};
vector<int> selected;
int sol;

void init() {
  cin >> N >> K;
  arr.resize(N);
  for (int i=0; i<N; i++)
    cin >> arr[i];
  K -= 5;
}

bool checkSkip(int i) {
  for (int j=0; j<5; j++) {
    if (skip[j]-'a' == i) {
      return true;
    }
  }
  return false;
}

int check() {
  int ret = 0;
  for (int i=0; i<N; i++) {
    int cnt = 0;
    for (int j=0; j<selected.size(); j++) {
      cnt += wordmap[i][selected[j]];
    }
    if (cnt == wordcnt[i]) {
      ret++;
    }
  }
  return ret;
}

void dfs(int idx) {
  if (selected.size() == K) {
    sol = max(check(), sol);
    return;
  }
  if (idx == 26) return;
  if (checkSkip(idx)) {
    dfs(idx+1);
    return;
  }
  dfs(idx+1);
  selected.push_back(idx);
  dfs(idx+1);
  selected.pop_back();
}

int solve() {
  sol = 0;
  if (K<0)
    return 0;
  memset(wordmap, 0, sizeof(wordmap));
  memset(wordcnt, 0, sizeof(wordcnt));
  for (int i=0; i<N; i++) {
    for (int j=0; j<arr[i].size(); j++) {
      if (checkSkip(arr[i][j]-'a')) continue;
      wordmap[i][arr[i][j]-'a'] = true;
    }
  }
  for (int i=0; i<N; i++) {
    for (int j=0; j<26; j++) {
      wordcnt[i] += wordmap[i][j];
    }
  }
  dfs(0);
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() << endl;
}
