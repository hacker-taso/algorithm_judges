// Retry
// https://algospot.com/wiki/old/552/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98_%EB%8C%80%ED%9A%8C%EC%97%90_%ED%95%84%EC%9A%94%ED%95%9C_%EC%88%98%ED%95%99
// https://www.topcoder.com/community/data-science/data-science-tutorials/algorithm-games/
// http://kmjp.hatenablog.jp/entry/2016/11/03/0900
// Start at 11:11 PM Feb 16, 2018
// End at 11:35PM Feb 16, 2018
// Retrospection:
// 1. From the view of A(Alice), if for A's valid move i, isWinB[curStones - i] is win, then
// isWinA[curStones] = false, otherwise isWinA[curStones] = true.
// Because if isWinB[curStones-(1~maxMove(A))] is same with isWinB[curStones'-(1~maxMove(A))],
// isWinA[curStones] = isWinA[curStones'] and maxMove(A) is 10 in max and also
// there can be only 2^10 cases for a sequence with lenght 10,
// there should be a cycle in 2^10 length.
// 2. I didn't consider the case where there's no move in a or b.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isWinA[4001];
bool isWinB[4001];

class PartisanGame {
private:
    bool isCycleA(int start, int end, int sizeA) {
        for (int i=0; i<sizeA; i++) {
            if (isWinB[start-i] != isWinB[end-i]) // B. Because B affects A.
                return false;
        }
        return true;
    }
    public:
    string getWinner(int n, vector <int> a, vector <int> b) {
        isWinA[0] = false;
        isWinB[0] = false;
        for (int i=1; i<=4000; i++) {
            for (int j=0; j<a.size(); j++) {
                if (0<=i-a[j] && (isWinB[i-a[j]] == false)) {
                    isWinA[i] = true;
                    break;
                }
                isWinA[i] = false;
            }
            for (int j=0; j<b.size(); j++) {
                if (0<=i-b[j] && (isWinA[i-b[j]] == false)) {
                    isWinB[i] = true;
                    break;
                }
                isWinB[i] = false;
            }
        }
        int end = 2000;
        int start = end-1;
        if (max_element(a.begin(), a.end()) == a.end())
            return "Bob";
        while (!isCycleA(start, end, *max_element(a.begin(), a.end()))) start--;
        int cycleSize = end-start;
        if (4000<n) n = 2000 + (n-2000) % cycleSize;
        if (isWinA[n])
            return "Alice";
        else
            return "Bob";
    }
};
