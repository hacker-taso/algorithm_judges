// Retry
// Start at 09:45PM Feb 18, 2018
// end at 10:25PM Feb 18, 2018
// Retrospection:
// 1. Mistake1: using 1 instead of 1ul.
// 2. Mistake2: not considering cycle prevention. (check candidate node can reach current node or not)
// 3. Mistake3: setting not constructed node as a candidate
//  candidate (j) should be smaller than cur idx (i)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DAGConstruction {
private:
    public:
    vector <int> construct(vector <int> x) {
        unsigned long long reachable[50];
        vector<pair<int, int> > pairs;
        for (int i=0; i<x.size(); i++) {
            pairs.emplace_back(x[i], i);
            reachable[i] = 1ul<<i;
        }
        sort(pairs.begin(), pairs.end());
        vector<int> sol;
        for (int i=0; i<pairs.size(); i++) {
            for (int j=0; j<i; j++) {
                unsigned long long reachableCand = reachable[pairs[i].second]|reachable[pairs[j].second];
                if ( __builtin_popcountll(reachableCand) <= x[pairs[i].second] &&
                    !((reachable[pairs[j].second] >> pairs[i].second)&1) ) {
                    reachable[pairs[i].second] = reachableCand;
                    sol.push_back(pairs[i].second);
                    sol.push_back(pairs[j].second);
                }
            }
            if (__builtin_popcountll(reachable[pairs[i].second]) != x[pairs[i].second])
                return vector<int>(1, -1);
        }
        return sol;
    }
};
