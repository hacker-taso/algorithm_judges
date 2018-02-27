// start from 02:08AM, Jan 25, 2018
// complete at 02:13AM, Jan 25, 2018
#include<iostream>
#include<set>
#include<vector>
using namespace std;

class DistinctGridEasy {
private:
    public:
    string checkGrid(int n, int k, vector <int> grid) {
        // row check
        for (int y=0; y<n; y++) {
            set<int> s;
            for (int x=0; x<n; x++) {
                s.insert(grid[n*y+x]);
            }
            if (s.size() != k)
                return "Bad";
        }
        // col check
        for (int x=0; x<n; x++) {
            set<int> s;
            for (int y=0; y<n; y++) {
                s.insert(grid[n*y+x]);
            }
            if (s.size() != k)
                return "Bad";
        }
        return "Good";
    }
};
