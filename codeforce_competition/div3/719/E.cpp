#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
using namespace std;
#define LT 0
#define RT 1
#define UP 2
#define DW 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int n;
int nsheep;
string s;
void init() {
  cin >> n;
  cin >> s;
}

long long solve() {
  nsheep = 0;
  for (int i=0; i<s.size(); i++)
    nsheep += s[i] == '*';
  int mididx;
  int tmp = 0;
  for (int i=0; i<s.size(); i++) {
    tmp += s[i] == '*';
    if (tmp == (nsheep+1)/2) {
      mididx = i;
      break;
    }
  }
  long long sol = 0;
  int ecnt = 0;
  for (int i=mididx+1; i<s.size(); i++) {
    if (s[i] == '.')
      ecnt++;
    if (s[i] == '*') 
      sol += ecnt;
  }
  ecnt = 0;
  for (int i=mididx-1; 0<=i; i--) {
    if (s[i] == '.')
      ecnt++;
    if (s[i] == '*')
      sol += ecnt;
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    cout << solve() << endl;
  }
}
