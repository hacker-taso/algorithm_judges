// start from 11:54PM, Jan 16, 2018
// complete at 12:05PM, Jan 16, 2018
// Retrospection:
// First time, I tried to find faster solution.
// But I chose easier solution.
// Refer: https://stackoverflow.com/questions/10402087/algorithm-for-minimum-manhattan-distance
// If a point is between middle two points then always manhattan distance is the smallest.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class SquareMaking {
    public:
    int getMinimalPrice(int a, int b, int c, int d) {
        vector<int> nums{a,b,c,d};
        sort(nums.begin(), nums.end());
        int sol = 0x12345678;
        int sum;
        for (int i=nums[0]; i<=nums[3]; i++) {
            sum = 0;
            for (int j=0; j<4; j++)
                sum += abs(i-nums[j]);
            sol = min(sol, sum);
        }
        return sol;
    }
};
