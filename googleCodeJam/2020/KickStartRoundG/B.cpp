#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
vector<vector<int>> board;
string s;

long long int solve() {
    long long int maxVal = 0;
    for (int x=0; x<N; x++) {
        long long int curVal = 0;
        for (int moveCnt=0; x+moveCnt<N; moveCnt++) {
            curVal += board[moveCnt][x+moveCnt];
        }
        maxVal = max(curVal, maxVal);
        curVal = 0;
        for (int moveCnt=0; x+moveCnt<N; moveCnt++) {
            curVal += board[x+moveCnt][moveCnt];
        }
        maxVal = max(curVal, maxVal);
    }
    return maxVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N;
        board = vector<vector<int>>(N, vector<int>(N));
        for (int y=0; y<N; y++)
            for (int x=0; x<N; x++)
                cin >> board[y][x];
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}