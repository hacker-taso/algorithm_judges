class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> cnts(100001, 0);
        for (int v: changed) {
            cnts[v]++;
        }
        if (cnts[0]%2 == 1)
            return {};
        vector<int> ret;
        while (cnts[0]) {
            cnts[0]-=2;
            ret.push_back(0);
        }
        for (int i=1; i<cnts.size(); i++) {
            if (0 < cnts[i]) {
                if (cnts.size() <= 2*i)
                    return {};
                while (cnts[i]) {
                    if (!cnts[2*i])
                        return {};
                    cnts[i]--;
                    cnts[2*i]--;
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
};