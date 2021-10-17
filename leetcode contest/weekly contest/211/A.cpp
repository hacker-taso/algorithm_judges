class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> pos(256, -1);
        vector<int> len(256, -1);
        for (int i=0; i<s.size(); i++) {
            if (pos[s[i]] != -1)
                len[s[i]] = i - pos[s[i]] - 1;
            else
                pos[s[i]] = i;
        }
        int ret =-1;
        for (int i='a'; i<='z'; i++) {
            if (len[i] != -1)
                ret = max(ret, len[i]);
        }
        return ret;
    }
};