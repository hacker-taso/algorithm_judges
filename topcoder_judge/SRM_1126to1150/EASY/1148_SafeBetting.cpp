// Start at 00:08AM Feb 23, 2018
// End at 00:12AM Feb 23, 2018
#include<iostream>
#include<vector>
using namespace std;

class SafeBetting {
private:
    public:
    int minRounds(int a, int b, int c) {
        int numBet = 0;
        while (b<c) {
            int curBet = b-a;
            b += curBet;
            numBet++;
        }
        return numBet;
    }
};
