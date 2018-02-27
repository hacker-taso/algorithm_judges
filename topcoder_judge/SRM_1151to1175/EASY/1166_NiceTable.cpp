// start from 11:23PM, Jan 22, 2018
// complete at 11:35PM, Jan 21, 2018
#include<iostream>
#include<vector>
using namespace std;
class NiceTable {
private:
    public:
    string isNice(vector <string> t) {
        vector<int> x(t.size(), 0);
        vector<int> y(t[0].size(), 0);
        // check x[0] = 0;
        for (int col=0; col<y.size(); col++) {
            y[col] = 0 ^ (t[0][col]-'0');
        }
        for (int row=0; row<x.size(); row++) {
            x[row] = y[0] ^ (t[row][0]-'0');
        }
        bool nice = true;
        for (int row=0; row<x.size(); row++) {
            for (int col=0; col<y.size(); col++) {
                if ((x[row]^y[col]) != (t[row][col]-'0')) {
                    nice = false;
                    break;
                }
            }
        }
        if (nice)
            return "Nice";
        // check x[0] = 1;
        for (int col=0; col<y.size(); col++) {
            y[col] = 1 ^ (t[0][col]-'0');
        }
        for (int row=0; row<x.size(); row++) {
            x[row] = y[0] ^ (t[row][0]-'0');
        }
        nice = true;
        for (int row=0; row<x.size(); row++) {
            for (int col=0; col<y.size(); col++) {
                if ((x[row]^y[col]) != (t[row][col]-'0')) {
                    nice = false;
                    break;
                }
            }
        }
        if (nice)
            return "Nice";
        else
            return "Not nice";
    }
};
