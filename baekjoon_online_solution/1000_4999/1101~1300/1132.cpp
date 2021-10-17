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
#define NEG_INF -987654321987654321ll
int N;
vector<string> arr;
void init() {
  cin >> N;
  arr.resize(N);
  for (int i=0; i<N; i++)
    cin >> arr[i];
}
long long summap[10][256];

void solve() {
  for (int i=0; i<10; i++) {
    for (char ch='A'; ch<='J'; ch++) {
      long long sum = 0;
      for (int j=0; j<arr.size(); j++) {
        if (i == 0 && arr[j][0] == ch) {
          sum = NEG_INF;
          break;
        }
        long long digit=1;
        for (int k=arr[j].size()-1; 0<=k; k--, digit*=10) {
          if (arr[j][k] == ch) {
            sum += digit*i;
          }
        }
      }
      summap[i][ch] = sum;
    }
  }

  string s = "0123456789";
  long long sol = 0;
  do {
    long long sum = 0;
    for (int i=0; i<s.size(); i++)
      sum += summap[s[i]-'0']['A'+i];
    sol = max(sol, sum);
  } while (next_permutation(s.begin(), s.end()));
  cout << sol <<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
