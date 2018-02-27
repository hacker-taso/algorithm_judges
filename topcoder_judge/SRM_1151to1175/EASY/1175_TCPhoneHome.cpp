// start from 09:06PM, Jan 31, 2018
// complete at 09:26PM, Jan 31, 2018
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class TCPhoneHome {
private:
    public:
    long long validNumbers(int digits, vector <string> specialPrefixes) {
        vector<string> refinedPrefixes;
        // if str[i] doesn't include any str[j], then push to refined.
        for (int i=0; i<specialPrefixes.size(); i++) {
            bool includes = false;
            for (int j=0; j<specialPrefixes.size(); j++) {
                if (i==j) continue;
                bool includesInner = true;
                if (specialPrefixes[i].size()<specialPrefixes[j].size()) continue;
                for (int pos=0; pos<specialPrefixes[j].size(); pos++) {
                    if (specialPrefixes[i][pos] != specialPrefixes[j][pos]) {
                        includesInner = false;
                        break;
                    }
                }
                if (includesInner) {
                    includes = true;
                    break;
                }
            }
            if (!includes)
                refinedPrefixes.push_back(specialPrefixes[i]);
        }
        long long allCnt = powl(10, digits);
        for (int i=0; i<refinedPrefixes.size(); i++) {
            allCnt -= powl(10, digits-refinedPrefixes[i].size());
        }
        return allCnt;
    }
};
