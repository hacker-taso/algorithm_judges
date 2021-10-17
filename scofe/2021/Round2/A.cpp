#include <iostream>
#include <vector>
using namespace std;
vector<int> songs;
int trainLen;

void solve() {
  // sum: sum([start, end])
  int start = -1, end = -1, sum = 0;
  int maxStart = 0, maxCnt = 1;
  
  while (start<(int)songs.size()) {
    if (0<=start)
      sum -= songs[start];
    start++;
    if (sum < trainLen) {
      while (end+1 < (int)songs.size()) {
        end++;
        sum += songs[end];
        if (trainLen <= sum)
          break;
      }
    } else
      continue;
    if (maxCnt < end - start + 1) {
      maxCnt = end - start + 1;
      maxStart = start;
    }
  }
  
  cout << maxCnt << " " << maxStart+1 << endl;
}

int main() {
  int N;
  string tmp;
  cin >> N;
  cin >> tmp;
  trainLen = (tmp[0]-'0') * 36000 + (tmp[1]-'0') * 3600
    + (tmp[3]-'0') * 600 + (tmp[4]-'0') * 60
    + (tmp[6]-'0') * 10 + (tmp[7]-'0');
  songs.resize(N);
  for (int i=0; i<N; i++) {
    cin >> tmp;
    songs[i] = (tmp[0]-'0') * 600 + (tmp[1]-'0') * 60
    + (tmp[3]-'0') * 10 + (tmp[4]-'0');
  }
  solve();
} 