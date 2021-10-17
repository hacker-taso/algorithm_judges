#include <iostream>
#include <iomanip>
#include <vector>
#define H 0
#define M 1
using namespace std;
int N;
int st, et;
vector<int> startList;
vector<int> endList;
int getHour(int n) {
  return n/60;
}
int getMinute(int n) {
  return n%60;
}
bool solve() {
  st = 0;
  et = 23*60 + 59;
  for (int i=0; i<N; i++) {
    if (et < startList[i] || endList[i] < st)
      return false;
    st = max(startList[i], st);
    et = min(endList[i], et);
  }
  return true;
}

int main() {
  string s;
  getline (cin, s);
  N = stoi(s);
  startList = vector<int>(N, 0);
  endList = vector<int>(N, 0);
  for (int i=0; i<N; i++) {
    getline (cin, s);
    startList[i] = ((s[0]-'0')*10 + s[1]-'0')*60;
    startList[i] += (s[3]-'0')*10 + s[4]-'0';
    endList[i] = ((s[8]-'0')*10 + s[9]-'0')*60;
    endList[i] += (s[11]-'0')*10 + s[12]-'0';
  }
  if (!solve()) {
    cout << -1 << endl;
    return 0;
  }
  cout << std::setfill('0') << std::setw(2) << getHour(st);
  cout << ":";
  cout << std::setfill('0') << std::setw(2) << getMinute(st);
  cout << " ~ ";
  cout << std::setfill('0') << std::setw(2) << getHour(et);
  cout << ":";
  cout << std::setfill('0') << std::setw(2) << getMinute(et);
  cout <<endl;
  return 0;
}

#include <iostream>
#include<vector>
using namespace std;
int N;
string s;
vector<long long> dp;

long long solve() {
  dp = vector<long long>(N, 0);
  dp[0] = 1;
  dp[1] = (s[1] == '0') ? 0 : 1;
  for (int i=2; i<N; i++) {
    if (s[i] == '0') {
      dp[i] = 0;
      continue;
    }
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp.back();
}

int main() {
  cin >> N;
  cin >> s;
  cout << solve() << endl;
  return 0;
}


#include <iostream>
#include <vector>
#define Y 0
#define X 1
using namespace std;
int N, total;
vector<string> board;
vector<vector<int>> axes[51]; // y,x list
bool solveLen(int len);

void init() {
  for (int i=0; i<51; i++)
    axes[i] = vector<vector<int>>();
}
void solve() {
  total = 0;
  init();
  for (int y=0; y<board.size(); y++) {
    for (int x=0; x<board[y].size(); x++) {
      if (board[y][x] == '1') {
        total++;
        axes[1].push_back(vector<int>{y, x});
      }
    }
  }
  for (int i=2; i<51; i++) {
    if (!solveLen(i))
      return;
  }
}
bool solveLen(int len) {
  bool updated = false;
  for (int i=0; i < axes[len-1].size(); i++) {
    bool allOne = true;
    int ltY = axes[len-1][i][Y], ltX = axes[len-1][i][X];
    int newY = ltY + len - 1, newX = ltX + len - 1;
    if (N <= newY || N <= newX)
      continue;
    for (int y=ltY; y<=newY; y++) {
      if (board[y][newX] == '0') {
        allOne = false;
        break;
      }
    }
    for (int x=ltX; x<=newX; x++) {
      if (board[newY][x] == '0') {
        allOne = false;
        break;
      }
    }
    if (allOne) {
      axes[len].push_back(vector<int>{ltY, ltX});
      updated = true;
      total++;
    }
  }
  return updated;
}

int main() {
  cin >> N;
  board = vector<string>(N);
  for (int i=0; i<N; i++) {
    cin >> board[i];
  }
  solve();
  cout << "total: " << total << endl;
  for (int i=1; i<51; i++) {
    if (axes[i].size() == 0)
      return 0;
    cout << "size[" << i << "]: " << axes[i].size() << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int preferences[5];
vector<string> genreBoard, watchBoard;
vector<vector<int>> sols; // y,x vector
vector<vector<int>> ranks;
int N, M;
int genreToNo(char genre) {
  return genre - 'A';
}
char noToGenre(int no) {
  return (char)(no + 'A');
}
string toFloatS(int n) {
  return to_string(n/10) + "." + to_string(n%10);
}
void check(char);

void solve() {
  check('Y');
  check('O');
}
void check(char watch) {
  for (int rankIdx = 0; rankIdx < ranks.size(); rankIdx++) {
    vector<int> genreNos = ranks[rankIdx];
    for (int y=0; y<N; y++) {
      for (int x=0; x<M; x++) {
        if (watchBoard[y][x] != watch)
          continue;
        int curGenreNo = genreToNo(genreBoard[y][x]);
        if (find(genreNos.begin(), genreNos.end(), curGenreNo) == genreNos.end())
          continue;
        sols.push_back(vector<int>({y, x}));
      }
    }
  }
}

int main() {
  string s;
  vector<int> tmp;
  for (int i=0; i<5; i++) {
    cin >> s;
    preferences[i] = (s[0]-'0')*10 + s[2]-'0';
    tmp.push_back(preferences[i]);
  }
  cin >> N >> M;
  watchBoard = genreBoard = vector<string>(N);
  for (int i=0; i<N; i++) {
    cin >> watchBoard[i];
  }
  for (int i=0; i<N; i++) {
    cin >> genreBoard[i];
  }
  
  sort(tmp.begin(), tmp.end(), greater<int>());
  for (int i=0; i<tmp.size(); i++) {
    if (i != 0 && tmp[i] == tmp[i-1])
      continue;
    vector<int> curRank;
    for (int j=0; j<5; j++) {
      if (preferences[j] == tmp[i])
        curRank.push_back(j);
    }
    ranks.push_back(curRank);
  }
  
  solve();
  for (int i=0; i<sols.size(); i++) {
    int y = sols[i][0], x = sols[i][1];
    char genre = genreBoard[y][x];
    string score = toFloatS(preferences[genreToNo(genre)]);
    cout << genre << " " << score << " " << y << " " << x << endl;
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib> 
#define INF 1234567890
#define START 'c'
#define NO 'x'
#define YES '.'
using namespace std;
vector<string> board;
int width, height;
vector<vector<int>> dp;

void initFirstRow() {
  for (int x=0; x<width; x++) {
    if (board[0][x] != START)
      continue;
    dp[0][x] = 0;
    for (int x2=x-1; 0<=x2; x2--) {
      if (board[0][x2] == NO || board[0][x2] == START)
        break;
      int dist = x - x2;
      dp[0][x2] = min(dp[0][x2], dist);
    }
    for (int x2=x+1; x2<width; x2++) {
      if (board[0][x2] == NO || board[0][x2] == START)
        break;
      int dist = x2 - x;
      dp[0][x2] = min(dp[0][x2], dist);
    }
  }
}
int solve() {
  initFirstRow();
  for (int y=1; y<height; y++) {
    int aboveY = y-1;
    for (int x=0; x<width; x++) {
      if (board[y][x] == NO)
        continue;
      dp[y][x] = dp[aboveY][x];
      for (int aboveX=x-1; 0<=aboveX; aboveX--) {
        if (board[y][aboveX] == NO)
          break;
        int dist = abs(x - aboveX);
        dp[y][x] = min(dp[y][x], dp[aboveY][aboveX] + dist);
      }
      for (int aboveX=x+1; aboveX<width; aboveX++) {
        if (board[y][aboveX] == NO)
          break;
        int dist = abs(x - aboveX);
        dp[y][x] = min(dp[y][x], dp[aboveY][aboveX] + dist);
      }
    }
  }
  int sol = INF;
  for (int x=0; x<width; x++)
    sol = min(sol, dp[height-1][x]);
  if (sol == INF)
    return -1;
  return sol;
}

int main() {
  cin >> width >> height;
  board = vector<string>(height);
  for (int y=0; y<height; y++) {
    cin >> board[y];
  }
  dp = vector<vector<int>>(height);
  for (int i=0; i<dp.size(); i++)
    dp[i] = vector<int>(width, INF);
  cout << solve() << endl;
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> board;
int width, height;

void solve() {
  dp[0][0] = board[0][0];
  for (int x=1; x<width; x++)
    dp[0][x] = dp[0][x-1] + board[0][x];
  for (int y=1; y<height; y++)
    dp[y][0] = dp[y-1][0] + board[y][0];
  for (int y=1; y<height; y++) {
    for (int x=1; x<width; x++) {
      dp[y][x] = max(dp[y-1][x], dp[y][x-1]) + board[y][x];
    }
  }
}

int main() {
  cin >> width >> height;
  board = vector<vector<int>>(height);
  for (int y=0; y<height; y++) {
    board[y] = vector<int>(width);
    for (int x=0; x<width; x++)
      cin >> board[y][x];
  }
  dp = vector<vector<int>>(height);
  for (int i=0; i<height; i++)
    dp[i] = vector<int>(width, 0);
  solve();
  cout << dp[height-1][width-1] << endl;
  return 0;
}