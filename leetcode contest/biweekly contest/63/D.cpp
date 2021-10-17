//not solved
class Solution {
public:
    bool check(vector<int>& arr1, vector<int>& arr2, bool isneg) {
        arr1[0]
    }
 
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<int> negs[2] = {0}, zeros[2], poss[2];
        for (int num: nums1) {
            if (num < 0)
                negs[0].push_back(num);
            else if (num == 0)
                zeros[0].push_back(num);
            else
                pluss[0].push_back(num);
        }
        for (int num: nums2) {
            if (num < 0)
                negs[1].push_back(num);
            else if (num == 0)
                zeros[1].push_back(num);
            else
                pluss[1].push_back(num);
        }
        long long minus = (long long)negs[0].count() * poss[1].count() + (long long)negs[1].count()*poss[0].count();
        long long zerocnt = (long long)zeros[0].count()*nums2.size() + (long long)nums1.size()*zeros[1].count();
        if (k<=minus) {
            return minus;
        } else if (k<=zerocnt) {
            return 0;
        } else {
            return plus;
        }
    }
};