// start from 03:37PM, Jan 16, 2018
// suspend from 05:00PM to 05:36PM.
// complete at 05:44PM, Jan 16, 2018
// Retrospection:
// 1. I figured out this problem well. But because I started all over again several times,
//  it took too much time(about 2 hours) for this problem.
//  It was caused by wrong design for code.
//  First time I thought this problem was very easy and 
//  I can make program satisfy condition just by
//  repeating place 1 to smallest index having 0 and counting consecutive 1s.
//  But there was counter examples for this solution. (100,2 => 110. not 111)
//  I think next time I need to check design first with more examples (about 3~5?).
// 2. I omitted "left += leftOne" after "left += leftOne".
#include<iostream>
using namespace std;
class ConsecutiveOnes {
    long long makeKOnes(int k) {
        long long ones = 0;
        for (int i=0; i<k; i++) {
            ones = (ones<<1) | 1;
        }
        return ones;
    }
    long long getLeft(long long n, long long ones) {
        long long mask = ~(ones | (ones-1));
        return n & mask;
    }
    long long getRight(long long n, long long ones) {
        long long mask = (ones & -ones) - 1;
        return n & mask;
    }
    public:
    long long get(long long n, int k) {
        long long ones = makeKOnes(k);
        long long left, right, candidate;
        long long sol = 0x1234567812345678;
        while (((ones>>55) & 1) == 0) {
            left = getLeft(n, ones);
            right = getRight(n, ones);
            //left part is larger, right part is 0
            long long leftOne = left & -left;
            if (!leftOne) {
                long long leftAllOnes = ~(ones | (ones-1));
                leftOne = leftAllOnes & -leftAllOnes;
            }
            left += leftOne;
            candidate = left | ones;
            sol = min(candidate, sol);
            // left part is same, ones + right part is bigger or equal.
            left -= leftOne;
            candidate = left | ones;
            if (candidate < n) {
                candidate |= right;
            }
            sol = min(candidate, sol);
            ones = ones<<1;
        }
        return sol;
    }
};
