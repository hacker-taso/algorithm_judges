// 끝나고 10분뒤 accepted됨.
// allSum - rangeSum(start, end) == p * x
// (allSum - rangeSum) % p == 0
// allSum % p == rangeSum % p (target 이라고 칭함)

// (curSum - prefixSum[?]) % p = target
// (curSum - target) % p = prefixSum[?]
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<int> prefixSum(nums.size(), 0);
        prefixSum[0] = nums[0] % p;
        for (int i=1; i<nums.size(); i++)
            prefixSum[i] = (nums[i] + prefixSum[i-1]) % p;
        int target = prefixSum[nums.size()-1];
        // rangeSum % p 가 target이면 됨.
        if (target == 0)
            return 0;
        
        int minSize = numeric_limits<int>::max();
        unordered_map<int, int> um;
        um[0] = -1; // 이걸 빼먹어가지고 accepted가 안됐었음.
        for (int i=0; i<prefixSum.size(); i++) {
            // (p + prefixSum[i] - finding - target) % p == 0이되면 됨.
            // rangeSum%p == (p+prefixSum[i] - finding) % p == target
            int finding = (p + prefixSum[i] - target) % p;
            if (um.find(finding) != um.end())
                minSize = min(minSize, i - um[finding]);
            um[prefixSum[i]] = i;
        }
        if (minSize == nums.size())
            return -1;
        return minSize; 
    }
};