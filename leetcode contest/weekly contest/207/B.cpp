// (s.length-1) 개를 true, false로 선택 -> 2^(slength-1). check uniqueness: s.length
class Solution {
private:
    int ret;
public:
    int maxUniqueSplit(string s) {
        ret = 1;
        vector<string> curSplit;
        iterate(s, 0, 0, curSplit);
        return ret;
    }
    void iterate(string& s, int from, int idx, vector<string> curSplit) {
        string curS = string(s.begin()+from, s.begin()+idx+1);
        if (idx == s.size()-1) {
            if (!hasSame(curS, curSplit))
                ret = max(ret, (int)curSplit.size() + 1);
            return;
        }
        iterate(s, from, idx+1, curSplit); // pass this idx
        if (!hasSame(curS, curSplit)) {
            curSplit.push_back(curS); // include [from:idx]
            iterate(s, idx+1, idx+1, curSplit);
        }
    }
    bool hasSame(string& curS, const vector<string>& curSplit) {
        for (int i=0; i<curSplit.size(); i++) {
            if (curS == curSplit[i])
                return true;
        }
        return false;
    }
};