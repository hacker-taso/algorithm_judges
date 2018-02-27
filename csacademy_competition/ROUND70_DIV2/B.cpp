// Start at 00:44AM Feb 22, 2018
// End at 01:37AM Feb 22, 2018
#include <iostream>
#include <vector>
#include <cstring>
#define RIGHT 0
#define DOWN 1
#define INIT 2
using namespace std;
int dp[301][301][3];
int N, M;
vector<vector<int> > board;
int getLongest(int y, int x, int state) {
    int& ret = dp[y][x][state];
    if (ret != -1) return ret;
    if (board[y][x] == 0) {
        if (state == RIGHT)
            ret= -1234567;
        else
            ret = 0;
        return ret;
    }
    if (state==INIT) {
        if (x+1<M && board[y][x+1]==1) ret = 1+getLongest(y, x+1, RIGHT);
        else ret = 1;
    }
    else if (state == DOWN) {
        if (y+1<N && board[y+1][x]==1) ret = 1+getLongest(y+1, x, DOWN);
        else ret = 1;
    }
    else if (state == RIGHT) {
        ret = -1234567;
        if (y+1<N && board[y+1][x]==1) ret = 1+getLongest(y+1, x, DOWN);
        if (x+1<M && board[y][x+1]==1) ret = max(ret, 1+getLongest(y, x+1, RIGHT));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    board = vector<vector<int> >(N, vector<int>(M));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++)
            cin >> board[i][j];
    }
    int sol = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            sol = max(getLongest(i, j, INIT), sol);
        }
    }
    cout << sol <<endl;
    return 0;
}