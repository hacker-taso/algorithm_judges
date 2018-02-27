// start from 11:51PM, Jan 15, 2018
// complete at 12:02AM, Jan 16, 2018
// Retrospection:
// 1. First time, I thought I need not to count duplicate. But it did.
// 2. I didn't check digit == 0 before number%digit.
// 3. number should not be changed during iteration.
//  But I used "number" as changing value without numberIter.
#include<iostream>
using namespace std;
class DivisorDigits {
    public:
    int howMany(int number) {
        int cnt = 0;
        int numberIter = number;
        while (0<numberIter) {
            int digit = numberIter%10;
            if (digit != 0 && number % digit == 0) {
                cnt++;
            }
            numberIter = numberIter/10;
        }
        return cnt;
    }
};
