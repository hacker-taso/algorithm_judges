// start from 10:52PM, Jan 14, 2018
// complete at 11:02PM, Jan 14, 2018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class YahtzeeScore {
    public:
    int maxPoints(vector <int> toss) {
        vector<int> points(7, 0);
        for (int i=0; i<toss.size(); i++) {
            points[toss[i]]+=toss[i];
        }
        return *max_element(points.begin(), points.end());
    }
};
