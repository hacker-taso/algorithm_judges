// start from 09:33PM, Jan 21, 2018
// complete at 09:50PM, Jan 21, 2018
#include<iostream>
#include<vector>
using namespace std;
class ImageCompression {
private:
    public:
    string isPossible(vector <string> image, int k) {
        int n = image.size();
        int m = image[0].size();
        for (int yTop = 0; yTop<n; yTop+=k) {
            for (int xLeft = 0; xLeft<m; xLeft+=k) {
                char color = image[yTop][xLeft];
                for (int y=yTop; y<yTop+k; y++) {
                    for (int x=xLeft; x<xLeft+k; x++) {
                        if (image[y][x] != color)
                            return "Impossible";
                    }
                }
            }
        }
        return "Possible";
    }
};
