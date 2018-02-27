// Start at 03:12PM Feb 17, 2018
// end at 03:15PM Feb 17, 2018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TestTaking {
private:
    public:
    int findMax(int questions, int guessed, int actual) {
        int numTrue = actual;
        int numFalse = questions-actual;
        int numGuessTrue = guessed;
        int numGuessFalse = questions-guessed;
        return min(numTrue, numGuessTrue) + min(numFalse, numGuessFalse);
    }
};
