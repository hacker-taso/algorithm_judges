class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        queue<pair<int, int>> q;
        for (int i=0; i<arr.size(); i++)
            q.push(make_pair(i, arr[i])); // idx, culm
        
        int ret = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            ret += cur.second;
            int idx = cur.first;
            if (arr.size() <= idx + 2)
                continue;
            q.push(make_pair(idx+2, cur.second + arr[idx+1] + arr[idx+2]));
        }
        return ret;
    }
};