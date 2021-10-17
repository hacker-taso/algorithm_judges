#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N;
string I;
string O;
bool sol[50][50];
void solve() {
  memset(sol, 0, sizeof(sol));
  for (int s=0; s<N; s++) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      sol[s][cur] = true;
      if (cur != 0 && !sol[s][cur-1] && I[cur-1]=='Y' && O[cur] == 'Y') {
        q.push(cur-1);
      }
      if (cur != N-1 && !sol[s][cur+1] && I[cur+1] == 'Y' && O[cur] == 'Y' ) {
        q.push(cur+1);
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> N;
    cin >> I;
    cin >> O;
    solve();
    cout << "Case #" << i+1 << ":" << endl;
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        cout << (sol[i][j] ? 'Y' : 'N');
      }
      cout << endl;
    }
  }
}