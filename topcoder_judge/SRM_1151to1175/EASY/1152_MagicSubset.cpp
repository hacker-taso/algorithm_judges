// start from 03:26PM, Jan 16, 2018
// complete at 03:33PM, Jan 16, 2018
// Retrospection:
// I think I did well.
// First I separated cases and with comment, I wrote code.
// I realized that even if I write code after organizing my thinking,
//  it doesn't take a lot of time by completing.
#include<iostream>
#include<vector>
using namespace std;
class MagicSubset {
    public:
    int findBest(vector <int> values) {
        int maxVal = 0;
        int n = values.size();
        // include 0 => only choose minus
        int sum = values[0];
        for (int i=1; i<n; i++) {
            if (values[i] < 0)
                sum += values[i];
        }
        maxVal = max(maxVal, sum * (-1));
        // not include 0
        sum = 0;
        for (int i=1; i<n; i++) {
            if (0 < values[i])
                sum += values[i];
        }
        maxVal = max(maxVal, sum);
        return maxVal;
    }
};
