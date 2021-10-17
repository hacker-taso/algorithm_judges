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
#include<unordered_set>
using namespace std;
int L, n;
vector<int> arr;
unordered_set<int> visited;
void init() {
  cin >> L;
  arr.resize(L);
  for (int i=0; i<L; i++)
    cin >> arr[i];
  cin >> n;
}

void solve() {
  priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
  for(int i=0; i<arr.size(); i++)
    pq.push({0, arr[i]});
  arr.push_back(0);
  sort(arr.begin(), arr.end());
  for (int i=0; i<arr.size(); i++) {
    if (i+1 != arr.size()) {
      int start = arr[i]+1;
      int end = arr[i+1]-1;
      int rangesz = end - start + 1;
      int cnt = 0;
      for (int i=0; start+i <= end; i++) {
        // [start~start+i, start+i~end] - [start+i,start+i]
        long long sum = (long long)(i+1)*(end-start-i+1) - 1;
        pq.push({sum, start+i});
        cnt++;
        if (cnt == 100) break;
      }
    }
    if (i != 0) {
      int start = arr[i-1]+1;
      int end = arr[i]-1;
      int rangesz = end - start + 1;
      int cnt = 0;
      for (int i=0; start+i <= end; i++) {
        long long sum = (long long)(i+1)*(end-start-i+1) - 1;
        pq.push({sum, end-i});
        cnt++;
        if (cnt == 100) break;
      }
    }
  }
  int cnt = 0;
  while (!pq.empty()) {
    auto [sum, x] = pq.top();
    pq.pop();
    if (visited.find(x) != visited.end()) continue;
    visited.insert(x);
    cout << x;
    cnt++;
    if (cnt == n) {
      cout << endl;
      return;
    }
    cout << " ";
  }
  for (int num=arr.back()+1; cnt < n; num++, cnt++) {
    cout << num;
    if (cnt != n)
      cout << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
