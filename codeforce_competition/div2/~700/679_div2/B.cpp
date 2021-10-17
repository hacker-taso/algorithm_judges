#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, nRow, nCol;
vector<vector<int>> rows;
vector<vector<int>> cols;
vector<int> firstCol;

void solve() {
    vector<vector<int>> board(nRow);
    map<int, int> m;
    for (int y=0; y<rows.size(); y++) {
        m[rows[y][0]] = y;
    }
    for (int y=0; y<firstCol.size(); y++) {
        int rowIdx = m[firstCol[y]];
        board[y] = rows[rowIdx];
    }
    for (int y=0; y<board.size(); y++) {
        for (int x=0; x<board[0].size(); x++) {
            cout << board[y][x];
            if (x+1 < board[0].size())
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> nRow >> nCol;
        rows = vector<vector<int>>(nRow, vector<int>(nCol));
        for (int y=0; y<nRow; y++)
            for (int x=0; x<nCol; x++)
                cin >> rows[y][x];
        int first = rows[0][0], firstX;
        cols = vector<vector<int>>(nCol, vector<int>(nRow));
        for (int x=0; x<nCol; x++)
            for (int y=0; y<nRow; y++) {
                cin >> cols[x][y];
                if (first == cols[x][y])
                    firstX = x;
            }
        firstCol = cols[firstX];
        solve();
    }
}
