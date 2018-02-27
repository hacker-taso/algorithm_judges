// Start at 04:47PM Feb 17, 2018
// end at 04:51PM Feb 17, 2018
// Retrospection:
// Return value of input "1111111" should be 1 not 0.
// But I set minimum value to zero so it returned 0.
#include<iostream>
#include<vector>
using namespace std;

class AlternatingString {
private:
    public:
    int maxLength(string s) {
        if (s.size() == 1)
            return 1;
        int maxCnt=1;
        int cnt = 1;
        for (int i=1; i<s.size(); i++) {
            if (s[i]==s[i-1]) {
                cnt = 1;
            } else {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};
