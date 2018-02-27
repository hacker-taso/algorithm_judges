// Retry
// Start at 10:39PM Feb 18, 2018
// end at 11:47PM Feb 18, 2018
// It is not important how I distribute nodes with same d
//  as long as there are more than two nodes and at least two nodes are distributed
//  in other nodes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TreeDistanceConstruction {
private:
    public:
    vector <int> construct(vector <int> d) {
        vector<int> distIdxs[51];
        int biggetDist = 0;
        int smallestDist = 100;
        for (int i=0; i<d.size(); i++) {
            distIdxs[d[i]].push_back(i);
            biggetDist = max(d[i], biggetDist);
            smallestDist = min(d[i], smallestDist);
        }
        if ((biggetDist+1)/2 != smallestDist)
            return vector<int>(0);
        vector<int> sol;
        if (distIdxs[smallestDist].size()==2) {
            if (biggetDist%2 != 1) return vector<int>(0);
            sol.push_back(distIdxs[smallestDist][0]);
            sol.push_back(distIdxs[smallestDist][1]);
        } else if (distIdxs[smallestDist].size()==1) {
            if (biggetDist%2 != 0) return vector<int>(0);
        } else {
            return vector<int>(0);
        }
        for (int i=smallestDist+1; i<=biggetDist; i++) {
            if (distIdxs[i].size()<2)
                return vector<int>(0);
            for (int j=0; j<distIdxs[i].size(); j++) {
                sol.push_back(distIdxs[i-1][j%distIdxs[i-1].size()]);
                sol.push_back(distIdxs[i][j]);
            }
        }
        return sol;
    }
};
