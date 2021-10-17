struct oper{
    bool operator () (vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        if (rides.size() == 0)
            return 0;
        sort(rides.begin(), rides.end(), oper());
        map<int, long long> dp;
        for (int i=rides.size()-1; 0<=i; i--) {
            int s = rides[i][0];
            int e = rides[i][1];
            int t = rides[i][2];
            auto it = dp.lower_bound(e);
            long long curmax = e-s+t;
            if (dp.empty()) {
                dp[s] = curmax;
                continue;
            }
            if (it != dp.end()) {
                curmax += it->second;
            }
            long long untilmax = dp.begin()->second;
            if (untilmax < curmax) {
                dp[s] = curmax;
            }
        }
        if (dp.empty())
            return 0;
        return dp.begin()->second;
    }
};