// Start at 00:32AM March 01, 2018
// End at 00:52AM March 01, 2018
#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<vector<int> > board;
int nRows, nCols;
pair<int, int> to[501][501];
void init() {
    memset(to, -1, sizeof(to));
}

pair<int, int> getTo(int y, int x) {
    pair<int, int>& ret = to[y][x];
    if (ret.first != -1) return ret;
    int minX = 0, minY = 0;
    int minVal = 10000000;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            int thereY = y+i;
            int thereX = x+j;
            if (thereY==nRows || thereY == -1 || thereX==nCols || thereX==-1)
                continue;
            if (board[thereY][thereX] < minVal) {
                minVal = board[thereY][thereX];
                minY = thereY;
                minX = thereX;
            }
        }
    }
    if (minX == x && minY == y)
        ret = make_pair(y, x);
    else
        ret = getTo(minY, minX);
    return ret;
}

int main() {
    cin >> nRows >> nCols;
    init();
    board = vector<vector<int> >(nRows, vector<int>(nCols));
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cin >> board[i][j];
        }
    }
    vector<vector<int> > sol(nRows, vector<int>(nCols, 0));
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            pair<int, int> arrive = getTo(i, j);
            sol[arrive.first][arrive.second]++;
        }
    }
    
    for (int i=0; i<nRows; i++) {
        for (int j=0; j<nCols; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}