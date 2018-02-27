// Retry3
// https://kimiyuki.net/blog/2016/09/18/srm-698-easy/
// https://en.wikipedia.org/wiki/Edit_distance
// https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm
// It took a lot of time.
// Retrospection:
// 1. I didn't know Wagner-Fisher algorithm.
// 2. I couldn't find out I can get minimum number of operation to make a TT structure
//  by calculating the minimum edit distance of splitted two substring of a string.
#include<iostream>
#include<cmath>
using namespace std;

class RepeatString {
private:
    int editDistance(const string& s1, const string& s2) {
        int editDist[51][51];
        for (int i=0; i<=50; i++) {
            for (int j=0; j<=50; j++) {
                if (i==0) {
                    editDist[i][j] = j;
                    continue;
                }
                if (j==0) {
                    editDist[i][j] = i;
                    continue;
                }
                editDist[i][j] = 10000;
            }
        }
        for (int i=1; i<=s1.size(); i++) {
            for (int j=1; j<=s2.size(); j++) {
                editDist[i][j] = min(
                    min(editDist[i][j-1]+1, editDist[i-1][j]+1),
                    editDist[i-1][j-1]+(s1[i-1] != s2[j-1])
                );
            }
        }
        return editDist[s1.size()][s2.size()];
    }
    public:
    int minimalModify(string s) {
        int minDist = 10000;
        for (int i=0; i<=s.size(); i++) {
            string sub1 = s.substr(0, i);
            string sub2 = s.substr(i, s.size()-i);
            minDist = min(minDist, editDistance(sub1, sub2));
        }
        return minDist;
    }
};
