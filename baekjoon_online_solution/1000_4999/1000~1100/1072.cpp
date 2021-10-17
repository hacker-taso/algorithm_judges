#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
long long X, Y;

int solve() {
  // Z = floor(Y*100/X) -> Z+1 = floor((Y+N)*100/(X+N))
  // at least N should be, (Z+1)*(X+N) = (Y+N)*100
  // (Z+1)X + Z*N+N = Y*100 + N*100
  // N*(Z-99) = Y*100 - (Z+1)*X
  // N = ceil((Y*100 - (Z+1)*X)/(Z-99))
  long long Z = Y*100 / X;
  if (99 <= Z)
    return -1;
  long long numer = -(Y*100 - (Z+1)*X);
  long long denom = -(Z-99);
  return numer / denom + (numer%denom != 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> X >> Y;
  cout << solve() << endl;
}
