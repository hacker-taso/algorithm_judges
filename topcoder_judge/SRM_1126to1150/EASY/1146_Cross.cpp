// Start at 10:34PM Feb 22, 2018
// End at 10:46PM Feb 22, 2018
// Retrospection: I learned that reference type member variable should be initialized.
#include<iostream>
#include<vector>
using namespace std;

class Cross {
private:
    vector<string> _board;
    bool check(int y, int x) {
        if (y<0 || x<0 || _board.size()<=y || _board[0].size()<=x)
            return false;
        return _board[y][x] == '#';
    }
    const char dx[5] = {0, 1, -1, 0, 0};
    const char dy[5] = {0, 0, 0, 1, -1};
    public:
    string exist(vector <string> board) {
        _board = board;
        for (int y=0; y<board.size(); y++) {
            for (int x=0; x<board[0].size(); x++) {
                bool exists = true;
                for (int i=0; i<5; i++) {
                    if (!check(y+dy[i], x+dx[i])) {
                        exists = false;
                        break;
                    }
                }
                if (exists)
                    return "Exist";
            }
        }
        return "Does not exist";
    }
};
