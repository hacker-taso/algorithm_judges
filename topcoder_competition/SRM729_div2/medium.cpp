// start from 02:09AM, Feb 11, 2018
// end at 02:55 AM
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SoManyRectangles {
private:
    public:
    int maxOverlap(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2) {
        // x axis, rect index, delta, 
        vector< pair<double, pair<int, int> > > events;
        for (int i=0; i<x1.size(); i++) {
            events.push_back(make_pair(x1[i], make_pair(i, 1)));
            events.push_back(make_pair(x2[i]-0.1, make_pair(i, -1)));
        }
        sort(events.begin(), events.end());
        vector<int> curRects;
        int sol = 0;
        for (int i=0; i<events.size(); i++) {
            if (0 < events[i].second.second) {
                curRects.push_back(events[i].second.first);
            } else if (events[i].second.second < 0) {
                auto found = find(curRects.begin(), curRects.end(), events[i].second.first);
                if (found != curRects.end()) {
                    curRects.erase(found);
                }
            }
            // y axis, rectIdx, delta
            vector<pair<double, pair<int,int> > > yEvents;
            for (int j=0; j<curRects.size(); j++) {
                int rectIdx = curRects[j];
                yEvents.push_back(make_pair(y1[rectIdx], make_pair(rectIdx, 1)));
                yEvents.push_back(make_pair(y2[rectIdx]-0.1, make_pair(rectIdx, -1)));
            }
            sort(yEvents.begin(), yEvents.end());
            vector<int> curYRects;
            int cnt = 0;
            for (int j=0; j<yEvents.size(); j++) {
                if (0 < yEvents[j].second.second) {
                    curYRects.push_back(yEvents[i].second.first);
                } else {
                    auto found = find(curYRects.begin(), curYRects.end(), yEvents[i].second.first);
                    if (found != curYRects.end())
                        curYRects.erase(found);
                }
                cnt = max(cnt, (int)curYRects.size());
            }
            sol = max(cnt, sol);
        }
        return sol;
    }
};
