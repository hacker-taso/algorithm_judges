// We can use DP for the small set.
// We can store the status of Ss and Ts in one integer with bit operations.
// O(# status * # move * # soldiers * # Test) = O(20C10 * 900 * 10 *100) ~= 10^11 -> Too slow
// We can store the reachability from S to T by T status
//   => O(# ST status * # S * #T * # Test) + O(# T status * # S * size of board * #Test)
//   ~= O(20C10 * 10 * 10 * 100) + O(2^10 * 10 * 900 * 100) ~= 1 biliion
// An important part is representing reachability and visibility with bits.
// mistake:
// 1. using || instead of | => This makes only 1 or 0.
// 2. I used "return" for dfs and I changed it to bfs. To skip, I needed to "continue" but I didn't change.
// I referred a little bit of the solution.
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int stMaxShot[1234567];
int maxSAndT[1234567];
// reach[tStat][S], stat 0: killed or shot
int reach[1024][10];
bool visited[30][30];
int C, R, M;
vector<string> board;
const int dy[4] = { -1, 1, 0, 0 };
const int dx[4] = { 0, 0, -1, 1 };
int tCnt, sCnt;
int ty[10], tx[10], sy[10], sx[10];
// store bits which represent Ts
int canSee[30][30];
bool canSeeAny[30][30];
int toTId[30][30];
struct point {
  int y, x, m;
};

bool canMoveFinal(int y, int x) {
  return 0 <= y && y < R && 0 <= x && x < C && board[y][x] != '#';
}

bool canMove(int stat, int oy, int ox, int y, int x) {
  return canMoveFinal(y, x)
    && (board[y][x] != 'T' || !(1 << toTId[y][x] & stat))
    && !(canSee[oy][ox] & stat);
}

queue<point> q;
void bfsR(int stat, int sId, int oy, int ox, int curM) {
  q.push({ oy, ox, curM });
  while (!q.empty()) {
    point cur = q.front();
    q.pop();
    if (visited[cur.y][cur.x])
      continue;
    visited[cur.y][cur.x] = true;
    reach[stat][sId] = reach[stat][sId] | canSee[cur.y][cur.x];
    if (cur.m <= 0)
      continue;
    for (int i = 0; i < 4; i++) {
      int y = cur.y + dy[i], x = cur.x + dx[i];
      if (canMove(stat, cur.y, cur.x, y, x) && !visited[y][x]) {
        q.push({ y, x, cur.m - 1 });
      }
    }
  }
}

void calcReach(int stat) {
  for (int sId = 0; sId < sCnt; sId++) { // 1024 * 10 * 900
    memset(visited, 0, sizeof(visited));
    q = queue<point>();
    bfsR(stat, sId, sy[sId], sx[sId], M);
  }
}

void fillCanSee(int oy, int ox, int tId) {
  for (int i = 0; i < 4; i++) {
    for (int y = oy + dy[i], x = ox + dx[i]; canMoveFinal(y, x); y += dy[i], x += dx[i]) {
      canSee[y][x] = canSee[y][x] | (1 << tId);
    }
  }
}
void init() {
  memset(stMaxShot, -1, sizeof(stMaxShot));
  memset(reach, 0, sizeof(reach));
  memset(canSee, 0, sizeof(canSee));
  memset(toTId, 0, sizeof(toTId));
  sCnt = 0; tCnt = 0;
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (board[y][x] == 'S') {
        sy[sCnt] = y; sx[sCnt] = x;
        sCnt++;
      }
      else if (board[y][x] == 'T') {
        ty[tCnt] = y; tx[tCnt] = x;
        toTId[y][x] = tCnt;
        fillCanSee(y, x, tCnt);
        tCnt++;
      }
    }
  }
}

bool sExist(int stat, int sId) {
  return ((stat >> (sId + 10)) & 1) == 1;
}
bool tExist(int stat, int tId) {
  return ((stat >> tId) & 1) == 1;
}
bool reachable(int stat, int sId, int tId) {
  return ((reach[stat & ((1 << tCnt) - 1)][sId] >> tId) & 1) == 1;
}
int dfs(int stat) {
  int &saved = stMaxShot[stat];
  if (saved != -1) return saved;
  int maxShot = 0, maxST = 0;
  for (int sId = 0; sId < sCnt; sId++) {
    if (!sExist(stat, sId)) continue;
    for (int tId = 0; tId < tCnt; tId++) {
      if (!tExist(stat, tId)) continue;
      if (!reachable(stat, sId, tId)) continue;
      int curShot = dfs(stat ^ (1 << tId) ^ (1 << (sId + 10))) + 1;
      if (maxShot < curShot) {
        maxShot = curShot;
        maxST = 1 << tId | 1 << (sId + 10);
      }
    }
  }
  maxSAndT[stat] = maxST;
  saved = maxShot;
  return saved;
}

void solve() {
  init();
  for (int i = 0; i <= (1 << tCnt) - 1; i++)
    calcReach(i);
  int initStat = ((1 << (10 + sCnt)) - 1) ^ ((1 << 10) - 1) | ((1 << tCnt) - 1);
  dfs(initStat);
  cout << stMaxShot[initStat] << endl;
  int curStat = initStat;
  for (int i = 0; i < stMaxShot[initStat]; i++) {
    int sAndT = maxSAndT[curStat];
    for (int sId = 0; sId < sCnt; sId++) {
      if (sExist(sAndT, sId))
        cout << sId + 1 << " ";
    }
    for (int tId = 0; tId < tCnt; tId++) {
      if (tExist(sAndT, tId))
        cout << tId + 1 << endl;
    }
    curStat = curStat ^ sAndT;
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> C >> R >> M;
    board.resize(R);
    for (int y = 0; y < R; y++)
      cin >> board[y];
    cout << "Case #" << i << ": ";
    solve();
  }
}
