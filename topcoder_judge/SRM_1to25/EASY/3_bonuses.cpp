// start from 10:37PM, Jan 13, 2018
// complete at 10:53PM, Jan 13, 2018
// Mistake: I sorted with -bonus[i] rather than -points[i]
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Bonuses {
    public:
    vector<int> getDivision(vector<int> points) {
        int numEmployee = points.size();
        int total = 0;
        for (int i=0; i<points.size(); i++)
            total += points[i];
        vector<int> bonuses(points.size(), 0);
        int bonusRemain = 100;
        vector<pair<int, int> > employePair(numEmployee);
        for (int i=0; i<points.size(); i++) {
            bonuses[i] = points[i]*100/total;
            employePair[i] = make_pair(-points[i], i);
            bonusRemain -= bonuses[i];
        }
        sort(employePair.begin(), employePair.end());
        int i=0;
        while (0<bonusRemain) {
            int employeeIdx = employePair[i%numEmployee].second;
            bonuses[employeeIdx]++;
            i++;
            bonusRemain--;
        }
        return bonuses;
    }
};
