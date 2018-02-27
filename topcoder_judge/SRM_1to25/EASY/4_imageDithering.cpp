// start from 10:55PM, Jan 13, 2018
// complete at 11:07PM, Jan 13, 2018
// Retrospection:
// 1. It was difficult to understand problem.
// 2. Time complexity = O(numY*numX*numPattern).
// If I make boolean dictionary for patterns,
// I can reduce to O(numY*numX)
#include<iostream>
using namespace std;
class ImageDithering {
    public:
    int count(string dithered, vector<string> screen) {
        // dithered: no repeated patterns. len:[2,26] =>26
        // screen: [1,50] elements. ['A'-'Z'], 1~50 => 2500
        // all elments of screen have same number of characters
        int numPattern = dithered.size();
        int numY = screen.size(); 
        int numX = screen[0].size();
        int cnt = 0;
        for (int y=0; y<numY; y++) {
            for (int x=0; x<numX; x++) {
                for (int p=0; p<numPattern; p++) {
                    if (dithered[p] == screen[y][x]) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};
