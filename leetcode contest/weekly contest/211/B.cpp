class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string ret = s;
        for (int aCnt1=0; aCnt1<=9; aCnt1++) {
            string cur = incr(s, a, aCnt1);
            for (int bCnt=0; bCnt<s.size(); bCnt++) {
                string cur2 = rotate(cur, b, bCnt);
                if (cur2<ret)
                    ret = cur2;
            }
            cur = rotate(cur, b, 1);
            for (int aCnt2=0; aCnt2<=9; aCnt2++) {
                string cur2 = incr(cur, a, aCnt2);
                for (int bCnt=0; bCnt<s.size(); bCnt++) {
                    string cur3 = rotate(cur2, b, bCnt);
                    if (cur3<ret)
                        ret = cur3;
                }
            }
        }
        return ret;
    }
    string rotate(string s, int b, int bCnt) {
        int cnt = b*bCnt % s.size();
        if (cnt == 0)
            return s;
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin()+cnt);
        reverse(s.begin()+cnt, s.end());
        return s;
    }
    string incr(string s, int a, int aCnt) {
        string res;
        for (int i=0; i<s.size(); i++) {
            if (i % 2 == 0) {
                res += s[i];
                continue;
            }
            int n = s[i] - '0';
            int resN = (n + a*aCnt)%10;
            res += (char)(resN + '0');
        }
        return res;
    }
};