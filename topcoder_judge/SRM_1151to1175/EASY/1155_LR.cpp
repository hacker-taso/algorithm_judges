// start from 00:17AM, Jan 17, 2018
// complete 01:06AM at , Jan 17, 2018
// Explnation:
//  At first, I made some examples and investigated some patterns.
//  I found that LR = RL and LLR = LRL and so on.
// Retrospection:
// 1. I think finding patterns by solving by hand is not bad idea.
// 2. There was a mistake that I wrote down like "s[i] != t[i]" rather than "iterS[i] != t[i]".
// 3. There was integer flow and I didn't check.
#include<iostream>
#include<vector>
using namespace std;
class LR {
    bool R(vector<long long>& iterS) {
        bool intFlow = false;
        long long first = iterS[0];
        for (int i=1; i<iterS.size(); i++) {
            iterS[i-1] += iterS[i];
            if (((long long)1 << 60) < iterS[i-1])
                intFlow = true;
        }
        iterS[iterS.size()-1] += first;
        if (((long long)1 << 60) < iterS[iterS.size()-1])
            intFlow = true;
        return intFlow;
    }
    bool L(vector<long long>& iterS) {
        bool intFlow = false;
        long long last = iterS[iterS.size()-1];
        for (int i=iterS.size()-1; 0<i; i--) {
            iterS[i] += iterS[i-1];
            if (((long long)1 << 60) < iterS[i])
                intFlow = true;
        }
        iterS[0] += last;
        if (((long long)1 << 60) < iterS[0])
            intFlow = true;
        return intFlow;
    }
    int getNumL(vector<long long> s, const vector<long long>& t, int len) {
        bool intFlow = false;
        for (int numL = 0; numL<=len; numL++) {
            vector<long long> iterS = s;
            for (int i=0; i<numL; i++) {
                if (L(iterS)) {
                    intFlow = true;
                    break;
                }
            }
            for (int i=0; i<(len-numL); i++) {
                if (R(iterS)) {
                    intFlow = true;
                    break;
                }
            }
            if (intFlow) continue;
            bool same = true;
            for (int i=0; i<s.size(); i++) {
                if (iterS[i] != t[i]) {
                    same = false;
                    break;
                }
            }
            if (same) return numL;
        }
        return -1;
    }
    public:
    string construct(vector<long long> s, vector<long long> t) {
        int numL;
        for (int len=0; len<=100; len++) {
            numL = getNumL(s, t, len);
            if (0<=numL) {
                return string(numL, 'L')+string(len-numL, 'R');
            }
        }
        return "No solution";
    }
};
