// Start at 11:27PM Feb 22, 2018
// End at 00:06AM Feb 23, 2018
// Retrospection: I don't know why but recently I frequently omit some necessary code like return sol;
//  or sol.push_back.
#include<iostream>
#include<vector>
using namespace std;

class BalancedStrings {
private:
    public:
    vector <string> findAny(int N) {
        vector<string> sol;
        if (N<=26) {
            for (int i=0; i<N; i++) {
                sol.push_back(string(1, 'a'+i));
            }
            return sol;
        }
        int sim = 0;
        for (int i=0; i<N-2; i++) {
            sol.push_back(string(1, 'e'+i%('z'-'e'+1)));
            sim += (i/('z'-'e'+1));
        }
        string s1;
        for (int i=0; i<min(100, sim); i++) {
            s1 += 'a'+i%2;
        }
        sim -= min(100, max(sim,0))-1;
        sol.push_back(s1);
        if (sim == 0) return sol;
        s1.clear();
        for (int i=0; i<min(100,sim+1); i++) {
            s1 += 'c'+i%2;
        }
        sol.push_back(s1);
        return sol;
    }
};
