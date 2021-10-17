#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int N;
long long L;
struct ant{
  int street;
  long long dist;
  int order;
};
vector<ant> ants;

void solve() {
  long long sum = 0;
  unordered_map<long long, int> um;
  vector<int> cnts(3, 0);
  for (ant a: ants) {
    if (a.order == 0)
      um[a.dist]++;
  }
  for (auto [s, d, o]: ants) {
    if (o == 1) {
      cnts[s]++;
      sum += L - d;
    } else if (1 < um[d]) {
      cnts[s]++;
      sum += L + d;
    } else {
      cnts[(s+1)%3]++;
      sum += L + d;
    }
  }
  cout << sum << endl;
  cout << cnts[0] << " " << cnts[1] << " " << cnts[2] <<endl;
}

int main() {
  char tmp;
  long long tmp2;
  int tmp3;
  cin >> N >> L;
  ants = vector<ant>(N);
  for (int i=0; i<N; i++) {
    cin >> tmp >> tmp2 >> tmp3;
    ants[i] = {tmp-'A', tmp2, tmp3};
  }
  solve();
  return 0;
}
