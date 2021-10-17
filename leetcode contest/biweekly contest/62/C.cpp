class Solution {
public:
    int maxsame(string& answerKey, int k, char shouldsame) {
        int diffcnt = 0;
        int start = 0, end = 0;
        int ret = 0;
        while (start < answerKey.size() && end < answerKey.size()) {
            while (end<answerKey.size()) {
                if (answerKey[end] != shouldsame) {
                    diffcnt++;
                }
                if (k<diffcnt)
                    break;
                ret = max(ret, end-start+1);
                end++;
            }
            if (end == answerKey.size())
                break;
            while (answerKey[start] == shouldsame) {
                start++;
                continue;
            }
            start++;
            diffcnt--;
            ret = max(ret, end-start+1);
            end++;
        }
        return ret;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ret = 0;
        // true loop
        ret = maxsame(answerKey, k, 'T');
        // false loop
        ret = max(ret, maxsame(answerKey, k, 'F'));
        return ret;
    }
};