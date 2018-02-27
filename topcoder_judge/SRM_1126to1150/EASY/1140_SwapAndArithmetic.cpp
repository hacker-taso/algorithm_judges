// Start at 05:50PM Feb 17, 2018
// end at 05:53PM Feb 17, 2018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SwapAndArithmetic {
private:
    public:
    string able(vector <int> x) {
        sort(x.begin(), x.end());
        int d=x[1]-x[0];
        for (int i=2; i<x.size(); i++) {
            if (x[i]-x[i-1] != d)
                return "Impossible";
        }
        return "Possible";
    }
};
