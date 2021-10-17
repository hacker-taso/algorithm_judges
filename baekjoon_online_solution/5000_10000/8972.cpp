class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string s2 = s + ':' + rev;
        vector<int> pmt(s2.size(), 0);
        int begin = 1, matched = 0;
        while (begin+matched < pmt.size()) {
            if (s2[begin+matched] == s2[matched]) {
                matched++;
                pmt[begin + matched - 1] = matched;
            } else {
                if (matched == 0) begin++;
                else {
                    begin += matched - pmt[matched-1];
                    matched = pmt[matched-1];
                }
            }
        }
        int overlap = pmt.back();
        return rev.substr(0, rev.size()-overlap) + s;
    }
};
// above is kmp solution implemented after I read the solution.
// below is manacher's algorithm solution
/*class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = "#";
        for (char c: s) {
            s2 += string(1, c) + "#";
        }
        vector<int> rs(s2.size(), 0);
        int mr = 0, p = 0;
        for (int i=1; i<s2.size(); i++) {
            int r = 0;
            if (i <= mr) {
                int reflidx = p - (i-p);
                r = min(rs[reflidx], mr-i);
            }
            while (r+i<s2.size() && 0<=i-r && s2[i-r] == s2[i+r]) {
                rs[i] = r;
                r++;
            }
            if (mr < i+rs[i]) {
                mr = i+rs[i];
                p = i;
            }
        }
        int maxidx = 0;
        for (int i=0; i<rs.size(); i++) {
            if (i-rs[i] == 0) {
                maxidx = i+rs[i];
            }
        }
        string fronttmp = s2.substr(maxidx+1);
        string front;
        for (int i=0; i<fronttmp.size(); i++)
            if (fronttmp[i] != '#')
                front += fronttmp[i];
        reverse(front.begin(), front.end());
        return front+s;
    }
};*/