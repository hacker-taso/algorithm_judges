// loses if sum %3 == 2 and all remains 2 or sum%3 == 1 and all remains 1 or sum % 3 == 0 and all remains 3 (edge: nothing left)
// 
class Solution {
public:
    bool canwin(vector<int> cnts, int first) {
        int sum = first;
        cnts[first]--;
        bool ret = true;
        while (true) {
            if ((sum+1)%3 == 0 && 0 < cnts[2]) {
                cnts[2]--;
                sum += 2;
                ret = !ret;
            } else if ((sum+2)%3 == 0 && 0 < cnts[1]) {
                cnts[1]--;
                sum += 1;
                ret = !ret;
            } else if (0 < cnts[0]) {
                cnts[0]--;
                ret = !ret;
            } else {
                int cnt = cnts[2]+cnts[1] +cnts[0];
                return ret && cnt != 0;
            }
        }
        return false;
    }
    bool stoneGameIX(vector<int>& stones) {
        vector<int> cnts(3, 0);
        for (int i=0; i<stones.size(); i++) {
            stones[i] = stones[i]%3;
            cnts[stones[i]]++;
        }
        cnts[0] = cnts[0] % 2;
        bool ret = false;
        if (0 < cnts[1])
            ret = ret || canwin(cnts, 1);
        if (0 < cnts[2])
            ret = ret || canwin(cnts, 2);
        return ret;
    }
};