// Start at 00:05AM Feb 21, 2018
// End at 00:14:AM Feb 21, 2018
// Retrospection:
// I didn't consider curEaten. So, I wrote like "a-=numEaten;"
#include<iostream>
#include<vector>
using namespace std;

class ThreeIncreasing {
private:
    public:
    int minEaten(int a, int b, int c) {
        int numEaten = 0;
        if (c<=b) {
            int curEaten = b-c+1;
            numEaten+=b-c+1;
            b-=curEaten;
        }
        if (b<=a) {
            int curEaten = a-b+1;
            numEaten+=a-b+1;
            a-=curEaten;
        }
        if (a<=0)
            return -1;
        else
            return numEaten;
    }
};
