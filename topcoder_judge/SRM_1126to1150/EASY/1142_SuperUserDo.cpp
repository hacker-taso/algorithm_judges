// Start at 11:09PM Feb 20, 2018
// end at 11:16PM Feb 20, 2018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class SuperUserDo {
private:
    public:
    int install(vector <int> A, vector <int> B) {
        vector<pair<int, int> > Aidx;
        for (int i=0; i<A.size(); i++)
            Aidx.push_back(make_pair(A[i], i));
        sort(Aidx.begin(), Aidx.end());
        int cnt = 0;
        int begin = Aidx[0].first;
        int end = B[Aidx[0].second];
        for (int i=1; i<Aidx.size(); i++) {
            int curBegin = Aidx[i].first;
            int curEnd = B[Aidx[i].second];
            if (end<curBegin) {
                cnt+=end-begin+1;
                begin = curBegin;
                end = curEnd;
            } else {
                end = max(end, curEnd);
            }
        }
        cnt += end-begin+1;
        return cnt;
    }
};
