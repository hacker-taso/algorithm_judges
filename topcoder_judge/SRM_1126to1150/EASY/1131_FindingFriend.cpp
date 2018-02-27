// Retry3
// http://web.eecs.utk.edu/~plank/topcoder-writeups/2016/FindingFriend/index.html
// It took a lot of time.
// Retrospection:
// 1. I found the way early to differentiate whether a room can be friend's room or not.
//  But first I thought I should distribute members of a room and preserving the rank
//  where the last distributing member is.
//  But easier way was preserving leftovers.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class FindingFriend {
private:
    public:
    int find(int roomSize, vector <int> leaders, int friendPlace) {
        int roomNum = leaders.size();
        bool found = false;
        int cnt = 0;
        sort(leaders.begin(), leaders.end());
        leaders.push_back(roomSize*roomNum+1);
        for (int friendRoom=0; friendRoom<roomNum; friendRoom++) {
            if (leaders[friendRoom] == friendPlace) {
                found = true;
                break;
            }
            if (friendPlace < leaders[friendRoom])
                break;
            int leftOver = 0;
            cnt++;
            for (int room=0; room<roomNum; room++) {
                int needToFill = leaders[room+1] - leaders[room];
                if (leaders[room]<friendPlace && friendPlace<leaders[room+1])
                    needToFill--;
                if (room == friendRoom)
                    needToFill++;
                needToFill-=roomSize;
                needToFill-=leftOver;
                if (0<needToFill) {
                    cnt--;
                    break;
                }
                leftOver = -needToFill;
            }
        }
        if (found)
            return 1;
        return cnt;
    }
};
