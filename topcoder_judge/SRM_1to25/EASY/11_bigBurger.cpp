// start from 12:05AM, Jan 16, 2018
// complete at 12:20AM, Jan 16, 2018
// Retrospection:
// 1. First time, I initalized like "previousOrderAt=0".
//  But it was not big problem.
// 2. I think for this problem, I did good job.
//  Because previous problem was too easy, I was used to easy problems.
//  So, I was a bit confused. But I did well by thinking carefully.
#include<iostream>
#include<vector>
using namespace std;
class BigBurger {
    public:
    int maxWait(vector <int> arrival, vector <int> service) {
        int previousOrderAt = arrival[0];
        int maxVal = 0;
        int numPeople = arrival.size();
        for (int i=1; i<numPeople; i++) {
            int curOrderAt= max(previousOrderAt+service[i-1], arrival[i]);
            int waitTime = curOrderAt - arrival[i];
            maxVal = max(maxVal, waitTime);
            previousOrderAt = curOrderAt;
        }
        return maxVal;
    }
};
