/*
입력:
3
12:00 ~ 23:59
11:00 ~ 18:00
14:00 ~ 20:00

출력:
14:00 ~ 18:00
*/
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
