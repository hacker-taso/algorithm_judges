#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>> skills;

long long sum(vector<long long>& partialSum, int until) {
  if (partialSum.size() < until) return 0;
  return partialSum[until-1];
}

void solve() {
  vector<vector<long long>> partialSums(n);
  for (int u=0; u<skills.size(); u++) {
    partialSums[u] = vector<long long>(skills[u].size());
    if (skills[u].size() == 0)
      continue;
    partialSums[u][0] = skills[u][0];
    for (int s=1; s<skills[u].size(); s++) {
      partialSums[u][s] = partialSums[u][s-1] + skills[u][s];
    }
  }
  vector<pair<int,int>> order;
  for (int i=0; i<partialSums.size(); i++)
    order.push_back({partialSums[i].size(), i});
  sort(order.begin(), order.end());
  vector<vector<long long>> partialSums2;
  for (int i=0; i<partialSums.size(); i++)
    partialSums2.push_back(partialSums[order[i].second]);
  int initU = 0;
  for (int k=1; k<=n; k++) {
    long long total = 0;
    for (int u=initU; u<n; u++) {
      int sCnt = partialSums2[u].size();
      total += sCnt < k ? 0 : sum(partialSums2[u], sCnt - sCnt%k);
      if (sCnt < k)
        initU = u+1;
    }
    cout << total;
    if (k != n)
      cout << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, tmp;
  vector<int> us, ss;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n;
    us.resize(n);
    ss.resize(n);
    skills = vector<vector<int>>(n);
    for (int j=0; j<n; j++)
      cin >> us[j];
    for (int j=0; j<n; j++)
      cin >> ss[j];
    vector<pair<int, int>> ps;
    for (int j=0; j<n; j++)
      ps.push_back({ss[j], us[j]});
    sort(ps.begin(), ps.end(), greater<pair<int, int>>());
    for (int j=0; j<n; j++)
      skills[ps[j].second-1].push_back(ps[j].first);
    solve();
  }
}