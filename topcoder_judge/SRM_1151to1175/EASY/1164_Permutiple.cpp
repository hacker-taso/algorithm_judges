// start from 11:36PM, Jan 21, 2018
// complete at 11:46PM, Jan 21, 2018
#include<iostream>
#include<algorithm>
using namespace std;
class Permutiple {
private:
    public:
    string isPossible(int x) {
        int maxNum = 1;
        for (int tmp = x; tmp!=0; tmp /= 10) {
            maxNum *= 10;
        }
        string xs = to_string(x);
        sort(xs.begin(), xs.end());
        for (int i=2; i*x < maxNum; i++) {
            int cand = i*x;
            string cands = to_string(cand);
            sort(cands.begin(), cands.end());
            bool same = true;
            for (int j=0; j<xs.size(); j++) {
                if (cands[j] != xs[j]) {
                    same = false;
                    break;
                }
            }
            if (same == true)
                return "Possible";
        }
        return "Impossible";
    }
};
