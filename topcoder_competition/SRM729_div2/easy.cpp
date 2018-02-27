// start from 02:00AM, Feb 11, 2018
// end at 02:08
#include<iostream>
#include<vector>
using namespace std;

class BrokenChessboard {
private:
    public:
    int minimumFixes(vector <string> board) {
        int sol = 0x12345678;
        int cnt = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if ((i+j)%2 == 0 && board[i][j] != 'W') {
                    cnt++;
                } else if ((i+j)%2 == 1 && board[i][j] != 'B') {
                    cnt++;
                }
            }
        }
        sol = min(sol, cnt);
        cnt = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if ((i+j)%2 == 0 && board[i][j] != 'B') {
                    cnt++;
                } else if ((i+j)%2 == 1 && board[i][j] != 'W') {
                    cnt++;
                }
            }
        }
        sol = min(sol, cnt);
        return sol;
    }
};
