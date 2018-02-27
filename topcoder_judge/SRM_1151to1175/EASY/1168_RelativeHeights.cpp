// start from 09:28PM, Jan 23, 2018
// complete at 09:47PM, Jan 23, 2018
// complexity: N^2 for reducing + logN * N * N for set inserting.
// (N times -> logN comparison -> N element for vector) => O(N^2 logN)
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
class RelativeHeights {
private:
    public:
    int countWays(vector <int> h) {
        vector<pair<int,int> > preProfile;
        for (int i=0; i<h.size(); i++)
            preProfile.push_back(make_pair(-h[i], i));
        sort(preProfile.begin(), preProfile.end());
        vector<int> profile(h.size());
        for (int i=0; i<h.size(); i++)
            profile[preProfile[i].second] = i;
        set<vector<int> > s;
        for (int i=0; i<h.size(); i++) {
            vector<int> copy = profile;
            for (int j=0; j<h.size(); j++) {
                if (copy[i]<copy[j])
                    copy[j]--;
            }
            copy.erase(copy.begin()+i);
            s.insert(copy);
        }
        return s.size();
    }
};
