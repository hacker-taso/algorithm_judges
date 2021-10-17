// I read the solution.
// mistake: should have used ull instead of ul
// This code shows RE.
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
int C, R, M;
string board[100];
bool st[100][100];
int capacity[202][202];
int flow[202][202];
bool removedS[100], removedT[100];
int smatch[100], origsmatch[100], origtmatch[100];
int scnt, tcnt;
struct point {
  int y, x, m;
};
vector<pair<int, int>> sol;
point sposes[100];
point tposes[100];
struct lll {
  unsigned long long u, l;
};
lll setB(lll bits, int pos) {
  if (50 <= pos) bits.u = bits.u | (1ull << (pos-50));
  else bits.l = bits.l | (1ull << pos);
  return bits;
}
lll resetB(lll bits, int pos) {
  if (50 <= pos) bits.u = bits.u & ~(1ull << (pos-50));
  else bits.l = bits.l & ~(1ull << pos);
  return bits;
}
bool isSet(lll bits, int pos) {
  if (50 <= pos) return (bits.u >> (pos-50)) & 1;
  else return (bits.l >> pos) & 1;
}
lll orB(lll bits1, lll bits2) {
  return lll({ bits1.u | bits2.u, bits1.l | bits2.l });
}
bool isSetAny(lll bits) {
  return bits.l != 0 || bits.u != 0;
}
lll cansee[100][100];
lll scansee[100];
const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

bool canEyeMove(int y, int x) {
  return 0 <= y && y < R && 0 <= x && x < C && board[y][x] != '#';
}
bool canBodyMove(int y, int x) {
  return canEyeMove(y, x) && board[y][x] != 'T';
}
void fillStCanSee(int sId, bool eye) {
  queue<point> q;
  q.push(sposes[sId]);
  bool visited[100][100] = { 0 };
  while (!q.empty()) {
    point cur = q.front();
    q.pop();
    if (visited[cur.y][cur.x]) continue;
    visited[cur.y][cur.x] = true;
    scansee[sId] = orB(scansee[sId], cansee[cur.y][cur.x]);
    if (cur.m <= 0 || (!eye && isSetAny(cansee[cur.y][cur.x])))
      continue;
    for (int dir = 0; dir < 4; dir++) {
      int y = cur.y + dy[dir], x = cur.x + dx[dir];
      if (eye && canEyeMove(y, x) || canBodyMove(y, x))
        q.push({ y, x, cur.m - 1 });
    }
  }
}
void makeSt(bool eye) {
  memset(st, 0, sizeof(st));
  memset(scansee, 0, sizeof(scansee));
  for (int sid = 0; sid < scnt; sid++) {
    if (removedS[sid]) continue;
    fillStCanSee(sid, eye);
    for (int tid = 0; tid < tcnt; tid++) {
      if (removedT[tid]) continue;
      if (isSet(scansee[sid], tid)) {
        st[sid][tid] = true;
      }
    }
  }
}

int sToMid(int sid) {
  return sid + 2;
}
int tToMid(int tid) {
  return tid + 102;
}
void nFlow() {
  memset(flow, 0, sizeof(flow));
  while (true) {
    queue<int> q;
    q.push(0);
    vector<int> parent(202, -1);
    parent[0] = 0;
    while (!q.empty() && parent[1] == -1) {
      int here = q.front(); q.pop();
      for (int there = 0; there < 202; there++) {
        if (0 < capacity[here][there] - flow[here][there] && parent[there] == -1) {
          parent[there] = here;
          q.push(there);
        }
      }
    }
    if (parent[1] == -1) break;
    for (int p = 1; p != 0; p = parent[p]) {
      flow[parent[p]][p] += 1;
      flow[p][parent[p]] -= 1;
    }
  }
}

void fillCansee(int tId, int oy, int ox) {
  for (int dir = 0; dir < 4; dir++) {
    for (int y = oy + dy[dir], x = ox + dx[dir]; canEyeMove(y, x); y += dy[dir], x += dx[dir]) {
      cansee[y][x] = setB(cansee[y][x], tId);
    }
  }
}
void fillAllCansee() {
  memset(cansee, 0, sizeof(cansee));
  for (int tid = 0; tid < tcnt; tid++)
    if (!removedT[tid])
      fillCansee(tid, tposes[tid].y, tposes[tid].x);
}

void removeS(int sid) {
  removedS[sid] = true;
  origsmatch[sid] = -1;
  smatch[sid] = -1;
  board[sposes[sid].y][sposes[sid].x] = '.';
  sposes[sid] = { -1,-1,-1 };
}
void removeT(int tid) {
  removedT[tid] = true;
  origtmatch[tid] = -1;
  board[tposes[tid].y][tposes[tid].x] = '.';
  tposes[tid] = { -1,-1,-1 };
}

bool cvisited[202];
vector<int> tracks;
int first;
bool findCycle(int mid) {
  if (cvisited[mid]) {
    return mid == first;
  }
  cvisited[mid] = true;
  tracks.push_back(mid);
  for (int mid2 = 0; mid2 < 202; mid2++) {
    if (capacity[mid][mid2]) {
      if (findCycle(mid2))
        return true;
    }
  }
  tracks.pop_back();
  return false;
}

int alter() {
  int cnt = 0;
  fillAllCansee();
  // block st
  makeSt(false);
  vector<bool> used(tcnt, 0);
  for (int sid = 0; sid < scnt; sid++) {
    if (removedS[sid]) continue;
    for (int tid = 0; tid < tcnt; tid++) {
      if (removedT[tid]) continue;
      if (!st[sid][tid]) continue;
      if (origtmatch[tid] != -1) continue;
      if (!used[tid]) {
        sol.push_back({ sid, tid });
        removeS(sid);
        removeT(tid);
        used[tid] = true;
        cnt++;
      }
    }
  }
  if (0 < cnt)
    return cnt;

  memset(capacity, 0, sizeof(capacity));
  for (int s = 0; s < scnt; s++) {
    for (int t = 0; t < tcnt; t++) {
      if (st[s][t]) {
        capacity[sToMid(s)][tToMid(t)] = 1;
      }
      if (origsmatch[s] == t) {
        capacity[tToMid(t)][sToMid(s)] = 1;
      }
    }
  }
  memset(smatch, -1, sizeof(smatch));
  for (int s = 0; s < scnt; s++) {
    memset(cvisited, 0, sizeof(cvisited));
    tracks.clear();
    first = sToMid(s);
    if (findCycle(first)) {
      for (int i = 0; i < tracks.size(); i += 2) {
        smatch[tracks[i] - 2] = tracks[i + 1] - 102;
      }
      break;
    }
  }
  for (int sid = 0; sid < scnt; sid++) {
    if (removedS[sid]) continue;
    if (smatch[sid] != -1) {
      int tid = smatch[sid];
      sol.push_back({ sid, tid });
      removeT(tid);
      removeS(sid);
      cnt++;
    }
  }
  return cnt;
}

void init() {
  memset(removedS, 0, sizeof(removedS));
  memset(removedT, 0, sizeof(removedT));
  scnt = 0; tcnt = 0;
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (board[y][x] == 'T') {
        fillCansee(tcnt, y, x);
        tposes[tcnt++] = { y, x, M };
      }
      else if (board[y][x] == 'S') {
        sposes[scnt++] = { y, x, M };
      }
    }
  }
}

void solve() {
  init();

  // no block move st
  makeSt(true);
  memset(capacity, 0, sizeof(capacity));
  for (int s = 0; s < scnt; s++) {
    capacity[0][sToMid(s)] = 1;
    for (int t = 0; t < tcnt; t++) {
      if (st[s][t]) {
        capacity[sToMid(s)][tToMid(t)] = 1;
      }
      capacity[tToMid(t)][1] = 1;
    }
  }
  nFlow();
  memset(origsmatch, -1, sizeof(origsmatch));
  memset(origtmatch, -1, sizeof(origtmatch));
  for (int s = 0; s < scnt; s++) {
    for (int t = 0; t < tcnt; t++) {
      if (0 < flow[sToMid(s)][tToMid(t)]) {
        origsmatch[s] = t;
        origtmatch[t] = s;
      }
    }
  }

  sol.clear();
  while (true) {
    int cnt = alter();
    if (cnt == 0)
      break;
  }
  cout << sol.size() << endl;
  for (int i = 0; i < sol.size(); i++) {
    auto[s, t] = sol[i];
    cout << s + 1 << " " << t + 1 << endl;
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> C >> R >> M;
    for (int y = 0; y < R; y++)
      cin >> board[y];
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}
