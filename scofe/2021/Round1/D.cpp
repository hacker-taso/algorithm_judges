/*
입력:
4
1110
1110
0110
0000

출력:
total: 11
size[1]: 8
size[2]: 3
*/

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
