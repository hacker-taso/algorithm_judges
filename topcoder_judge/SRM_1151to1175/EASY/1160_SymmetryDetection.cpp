// start from 08:11PM, Jan 18, 2018
// complete at 08:19PM, Jan 18, 2018
#include<iostream>
#include<vector>
using namespace std;
class SymmetryDetection {
private:
    public:
    string detect(vector <string> board) {
        bool isHSym = true, isVSym = true;
        for (int y=0; y<board.size(); y++) {
            for (int x=0; x<board[y].size(); x++) {
                if (board[y][x] != board[board.size()-y-1][x])
                    isHSym = false;
                if (board[y][x] != board[y][board[y].size()-x-1])
                    isVSym = false;
            }
        }
        if (isHSym && isVSym)
            return "Both";
        else if (isHSym)
            return "Horizontally symmetric";
        else if (isVSym)
            return "Vertically symmetric";
        else
            return "Neither";
    }
};
