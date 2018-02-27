// Retry2
// start from 11:33PM, Feb 10, 2018
// it took about 1 hour to complete.
// Retrospection: 
// 1. the number of cases where each numbers allocated can be calculated like this.
//  a. select one number
//  b. select the number of used number of selected number
//  c. find the number of allocation by calculating binominal coefficiant nCr
//   where n is the number of position which can be allocated and r is the number of selected number.
// 2. I have a problem in base case of "occurence" function.
//  => it should be like "if (curDigit == 10) {
//          if (blanks == 0) return 1;
//          else return 0;
//     }"
#include<iostream>
#include<cstring>
#include<vector>
#define MOD 1000000007
using namespace std;

class SumProduct {
private:
    int cache[201][10][10][10];
    int binocoefCache[201][201];
    vector<int> amount;
    void init() {
        memset(cache, -1, sizeof(cache));
        memset(binocoefCache, -1, sizeof(binocoefCache));
    }
    int binocoef(int n, int r) {
        if (r == 0) return 1;
        if (n == r) return 1;
        int &ret = binocoefCache[n][r];
        if (ret != -1) return ret;
        ret = (binocoef(n-1, r-1) + binocoef(n-1, r)) % MOD;
        return ret;
    }
    // blanks: the number of all blanks. curDigit: it shows [0, curDigit) is allocated.
    // d1: it shows that d1 is allocated. d2: it shows that d2 is allocated.
    int occurence(int blanks, int curDigit, int d1, int d2) {
        if (curDigit == 10) {
            if (blanks == 0) return 1;
            else return 0;
        }
        int& ret = cache[blanks][curDigit][d1][d2];
        if (ret != -1) return ret;
        int cnt = 0;
        int curAmount = amount[curDigit];
        if (d1 == curDigit) curAmount--;
        if (d2 == curDigit) curAmount--;
        for (int i=0; i<=curAmount && i<=blanks; i++) {
            cnt = (cnt + (long long)occurence(blanks-i, curDigit+1, d1, d2)*binocoef(blanks, i)) % MOD;
        }
        ret = cnt;
        return ret;
    }
    public:
    int findSum(vector <int> _amount, int blank1, int blank2) {
        amount = _amount;
        init();
        int sum = 0;
        int centMod[100];
        centMod[0] = 1;
        for (int i=1; i<100; i++) {
            centMod[i] = (long long)centMod[i-1]*10 % MOD;
        }
        for (int p1=0; p1<blank1; p1++) {
            for (int p2=0; p2<blank2; p2++) {
                for (int d1=0; d1<10; d1++) {
                    if (amount[d1] == 0) continue;
                    for (int d2=0; d2<10; d2++) {
                        if (amount[d2] == 0) continue;
                        if (d1 == d2 && amount[d1] == 1) continue;
                        int num1 = ((long long)centMod[p1] * d1) % MOD;
                        int num2 = ((long long)centMod[p2] * d2) % MOD;
                        int mul = ((long long)num1 * num2) % MOD;
                        sum = (sum + (long long)occurence(blank1+blank2-2, 0, d1, d2)*mul) % MOD;
                    }
                }
            }
        }
        return sum;
    }
};
