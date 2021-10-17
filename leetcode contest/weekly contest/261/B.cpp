class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = mean*(n+rolls.size());
        for (int v: rolls)
            sum -= v;
        if (sum < n || n*6 < sum)
            return {};
        vector<int> ret(n, 1);
        sum -= n;
        for (int i=0; i<n; i++) {
            int added = min(5, sum);
            ret[i] += added;
            sum -= added;
        }
        return ret;
    }
};