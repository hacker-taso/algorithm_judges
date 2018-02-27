// start from 12:43AM, Jan 21, 2018
// complete at 12:46AM, Jan 21, 2018
// It was too easy..
#include<iostream>
#include<vector>
using namespace std;
class RangeEncoding {
private:
    public:
    int minRanges(vector <int> arr) {
        int cnt=0;
        for (int i=1; i<arr.size(); i++) {
            if (arr[i] != arr[i-1]+1)
                cnt++;
        }
        return cnt+1;
    }
};
