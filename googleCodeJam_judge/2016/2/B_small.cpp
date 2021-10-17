// split 16 to 8 and 8 -> 16 C 8 (6435) -> sum(calc prob) (8 C 4)
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<numeric>
using namespace std;
vector<double> ps;
bool visited[17][65536];
double maxp;
int N, K; // N C K

vector<int> selected;
vector<int> sel1;
vector<int> sel2;

double calcTie(int idx) { // K C (K/2)
  if (K/2 < sel1.size() || K/2 < sel2.size())
    return 0;
  if (idx == selected.size()) {
    if (sel1.size() == sel2.size()) {
      double sum1 = 0;
      for (int sel: sel1) // sel1 yes
        sum1 += log(ps[sel]);
      for (int sel: sel2) // sel2 no
        sum1 += log(1-ps[sel]);
      return exp(sum1);
    }
    return 0;
  }
  sel1.push_back(selected[idx]);
  double ret = calcTie(idx+1);
  sel1.pop_back();
  sel2.push_back(selected[idx]);
  ret += calcTie(idx+1);
  sel2.pop_back();
  return ret;
}

void select(int idx, int bi) {
  if (N < idx) return;
  if (visited[idx][bi]) return;
  visited[idx][bi] = true;
  if (selected.size() == K) {
    double res = calcTie(0);
    maxp = max(res, maxp);
    return;
  }
  select(idx+1, bi);
  for (int i=idx; i<N; i++) {
    selected.push_back(i);
    select(i+1, bi | (1<<i));
    selected.pop_back();
  }
}

double solve() {
  memset(visited, 0, sizeof(visited));
  selected.clear();
  sel1.clear();
  sel2.clear();
  maxp = 0;
  select(0, 0);
  return maxp;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> K;
    ps.resize(N);
    for (int j=0; j<N; j++) {
      cin >> ps[j];
    }
    cout << "Case #" << i << ": " << fixed << setprecision(9) << solve() <<endl;
  }
}
