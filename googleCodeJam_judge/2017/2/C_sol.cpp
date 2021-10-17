// I first thought this is network flow but it isn't
// I saw the solution.
#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>
#define V_LASER '|'
#define H_LASER '-'
#define WALL '#'
#define EMPTY '.'
#define SLASH '/'
#define REV_SL '\\'
using namespace std;
// true: up down
int tfs[2500];
int lCnt;
int R, C;
vector<string> board;

vector<vector<int>> adjList;
vector<int> sccId;
vector<int> discovered;
int sccCounter;
int discCounter;
stack<int> st;

int scc(int here) {
  int ret = discovered[here] = discCounter++;
  st.push(here);
  for (int i=0; i<adjList[here].size(); i++) {
    int there = adjList[here][i];
    if (discovered[there] == -1) {
      ret = min(ret, scc(there));
    } else if (sccId[there] == -1) {
      ret = min(ret, discovered[there]);
    }
  }
  if (ret == discovered[here]) {
    while (true) {
      int node = st.top();
      st.pop();
      sccId[node] = sccCounter;
      if (here == node) break;
    }
    sccCounter++;
  }
  return ret;
}
void tarjan() {
  st = stack<int>();
  discCounter = sccCounter = 0;
  sccId = discovered = vector<int>(lCnt*2, -1);
  for (int i=0; i<lCnt*2; i++) {
    if (discovered[i] == -1) scc(i);
  }
}

void impossible() {
  cout << "IMPOSSIBLE" <<endl;
}

bool isLaser(int y, int x) {
  return board[y][x] == H_LASER || board[y][x] == V_LASER;
}

int paths[50][50];
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};
const int slash_map[4] = {DOWN, UP, RIGHT, LEFT};
const int rev_sl_map[4] = {UP, DOWN, LEFT, RIGHT};
int visited[50][50];
bool isValid(int y, int x) {
  return 0<=y && y<R && 0<=x && x<C && board[y][x] != WALL;
}
int getNode(int lId, int dir) {
  return lId*2 + ((dir==LEFT) || (dir==RIGHT));
}
int notNode(int node) {
  return node - node%2 + (node+1)%2;
}
bool makeAdj(const int y, const int x, int dir, const int nodeId) {
  if (!isValid(y, x)) return true;
  if (isLaser(y, x)) return false;
  // visited cannot be more than 2 (if it is, it will destory the laser itself)
  visited[y][x]++;
  if (board[y][x] == SLASH) {
    dir = slash_map[dir];
  } else if (board[y][x] == REV_SL) {
    dir = rev_sl_map[dir];
  }
  bool possible = makeAdj(y+dy[dir], x+dx[dir], dir, nodeId);
  if (!possible) {
    visited[y][x]--;
    return false;
  }
  if (board[y][x] == EMPTY) {
    if (paths[y][x] != -1) {
      adjList[notNode(paths[y][x])].push_back(nodeId);
      adjList[notNode(nodeId)].push_back(paths[y][x]);
    } else
      paths[y][x] = nodeId;
  }
  return true;
}

bool possibleMap[50][50];

void makeAdjDriver(int dir1, int dir2) {
  int lId = 0;
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[y].size(); x++) {
      if (isLaser(y, x)) {
        int nodeId = getNode(lId, dir1);
        bool possible = makeAdj(y+dy[dir1], x+dx[dir1], dir1, nodeId);
        possible = possible && makeAdj(y+dy[dir2], x+dx[dir2], dir2, nodeId);
        if (!possible) {
          // !nodeId v !nodeId
          adjList[nodeId].push_back(notNode(nodeId));
        }
        possibleMap[y][x] = possible || possibleMap[y][x];
        lId++;
      }
    }
  }
}

bool fillNoAdj() {
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[y].size(); x++) {
      if (isLaser(y, x)) {
        if (!possibleMap[y][x]) return false;
      } else if (board[y][x] == EMPTY) {
        if (visited[y][x] == 0) return false;
        if (2 <= visited[y][x]) continue;
        adjList[notNode(paths[y][x])].push_back(paths[y][x]);
      }
    }
  }
  return true;
}

void setLCnt() {
  lCnt = 0;
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[y].size(); x++) {
      lCnt += isLaser(y, x);
    }
  }
}

void solve() {
  memset(paths, -1, sizeof(paths));
  memset(visited, 0, sizeof(visited));
  setLCnt();
  adjList = vector<vector<int>>(lCnt*2);
  memset(possibleMap, false, sizeof(possibleMap));
  makeAdjDriver(LEFT, RIGHT);
  makeAdjDriver(UP, DOWN);
  bool possible = fillNoAdj();
  if (!possible) {
    impossible();
    return;
  }

  tarjan();
  for (int i=0; i<lCnt*2; i+=2) {
    if (sccId[i] == sccId[i+1]) {
      impossible();
      return;
    }
  }
  vector<pair<int,int>> order;
  for (int i=0; i<lCnt*2; i++) {
    order.push_back({-sccId[i], i});
  }
  sort(order.begin(), order.end());
  memset(tfs, -1, sizeof(tfs));
  for (int i=0; i<order.size(); i++) {
    int here = order[i].second;
    int lId = here/2; bool isTrue = (here%2 == 0);
    if (tfs[lId] != -1) continue;
    tfs[lId] = !isTrue;
  }

  cout << "POSSIBLE" << endl;
  int lId = 0;
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[y].size(); x++) {
      if (isLaser(y, x)) {
        board[y][x] = (tfs[lId]==true) ? V_LASER : H_LASER;
        lId++;
      }
    }
    cout << board[y] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> R >> C;
    board.resize(R);
    for (int j=0; j<R; j++)
      cin >> board[j];
    cout << "Case #" << i << ": ";
    solve();
  }
}
