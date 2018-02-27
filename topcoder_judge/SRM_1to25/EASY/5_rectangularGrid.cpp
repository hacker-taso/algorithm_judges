// start from 00:23AM, Jan 14, 2018
// complete at 00:31AM, Jan 14, 2018
// Retrospection: I first tried to find solution in constant time
//  by all - squares.
// But all is (2^width - 1)*(2^height - 1) and it is too big.
#include<iostream>
using namespace std;
class RectangularGrid {
    public:
    long long countRectangles(int width, int height) {
        //2s, width, hegiht: [1,1000]
        long long cnt = 0;
        for (int y=1; y<=height; y++) {
            for (int x=1; x<=width; x++) {
                if (x==y) continue;
                long long yDir = (height-y)+1;
                long long xDir = (width-x)+1;
                cnt+=xDir*yDir;
            }
        }
        return cnt;
    }
};
