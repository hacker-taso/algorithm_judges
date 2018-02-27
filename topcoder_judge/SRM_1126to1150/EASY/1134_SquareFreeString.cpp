// Start at 02:30AM Feb 17, 2018
// end at 02:39AM Feb 17, 2018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SquareFreeString {
private:
    public:
    string isSquareFree(string s) {
        for (int start=0; start<s.size(); start++) {
            for (int end=start+1; end<s.size(); end++) {
                if (s.size()-1<end+end-start-1)
                    continue;
                bool square = true;
                for (int i=0; i<end-start; i++) {
                    if (s[start+i] != s[end+i])
                        square=false;
                }
                if (square)
                    return "not square-free";
            }
        }
        return "square-free";
    }
};
