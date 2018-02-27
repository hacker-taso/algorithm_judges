//https://kimiyuki.net/blog/2016/09/27/srm-699-easy/
// http://kenkoooo.hatenablog.com/entry/2016/09/27/054012
// Retry3
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class OthersXor {
private:
    public:
    long long minSum(vector <int> x) {
        long long sum = 0;
        for (int i=0; i<30; i++) {
            int numOne = 0;
            int numMinus = 0;
            for (int j=0; j<x.size(); j++) {
                if (x[j] == -1) {
                    numMinus++;
                    continue;
                }
                int bit = (x[j] >> i)&1;
                numOne += bit;
            }
            int numZero = x.size() - numOne - numMinus;
            // if xor of all is zero -> All saying zero should be zero, All saying one should be one.
            // Each saying minus could be anything.
            // num of one should be even.
            int curSum = 1000000;
            if (numOne%2 == 0) curSum = min(curSum, numOne);
            else if (numMinus>0) curSum = min(curSum, numOne+1);
            // if xor of all is one -> All saying zero should be one, All saying zero should be one.
            // num of zero should be odd.
            if (numZero%2 == 1) curSum = min(curSum, numZero);
            else if (numMinus>0) curSum = min(curSum, numZero+1);
            if (curSum == 1000000) return -1;
            sum = sum + ((long long)curSum << i);
        }
        return sum;
    }
};
