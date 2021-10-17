// learnt: 골드바흐의 추측(Goldbach's conjecture):
// any even numbers can be represented with sum of two prime numbers
// -> p1+p2+2+3 -> odd numbers from 9
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
int N;
vector<bool> pmap;
vector<int> primes;

vector<bool> getPrimeNumberMap(int until) {
  vector<bool> pm(until+1, true);
  pm[0] = pm[1] = false;
  for (int i=2; i*i<=until; i++) {
    for (int j=i*i; j<=until; j+=i) {
      pm[j] = false;
    }
  }
  return pm;
}

void init() {
  cin >> N;
  pmap = getPrimeNumberMap(1100000);
  for (int i=2; i<1100000; i++) {
    if (pmap[i])
      primes.push_back(i);
  }
}

void solve() {
  if (N<8) {
    cout << -1 << endl;
    return;
  }
  bool isEven = N%2 == 0;
  N -= !isEven; // make it even
  for (int i=2; i<N; i++) {
    if (pmap[i] && pmap[N-4-i]) {
      cout << i << " " << N-4-i;
      break;
    }
  }
  cout << " " << 2 << " " << (isEven ? 2 : 3) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
