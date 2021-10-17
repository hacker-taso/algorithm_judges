class Solution {
public:
    string reorderSpaces(string text) {
        int wCnt = 0, betweenCnt = 0;
        for (int i=0; i<text.size(); i++) {
            if (text[i] == ' ')
                wCnt++;
            if (i != 0 && text[i-1] != ' ' && text[i] == ' ')
                betweenCnt++;
        }
        if (text.back() == ' ')
            betweenCnt--;

        int allocCnt, remainCnt;
        if (betweenCnt == 0)
            allocCnt = 0;
        else
            allocCnt = wCnt / betweenCnt;
        if (betweenCnt == 0)
            remainCnt = wCnt;
        else
            remainCnt = wCnt % betweenCnt;

        string ret = "";
        for (int i=0; i<text.size(); i++) {
            if (text[i] != ' ')
                ret += text[i];
            else if (i != 0 && text[i-1] != ' ' && 0<betweenCnt) {// text[i] == ' '
                ret += string(allocCnt, ' ');
                betweenCnt--;
            }
        }
        ret += string(remainCnt, ' ');
        return ret;
    }
};