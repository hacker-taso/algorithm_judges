// Retry (after reading https://www.topcoder.com/blog/single-round-match-710-editorials/)
// start from 02:09PM, Feb 01, 2018
// complete at 03:13PM, Feb 01, 2018
// Retrospection:
// 1. This problem can be solved by making a cross point using just one operation.
//  I think there are 4 important factors to solve this problem.
//  1) What a cross point exactly should be?
//  2) How can I get to the cross point?
//  3) Knowing inverse operation.
//  4) Calculating the number of movements
// 2. The number of movements can be calculated by finding pattern.
//  In the editorial solution, the editor calculated this by noticing that the result of one movement can only be
//  1) Empty one slot
//   or
//  2) The last part increases.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ReverseMancala {
private:
    // return: last slot
    int Amove(vector<int>& seq, int slot) {
        int n = seq.size();
        int numRemain = seq[slot];
        seq[slot] = 0;
        while (numRemain) {
            slot = (slot+1)%n;
            seq[slot]++;
            numRemain--;
        }
        return slot;
    }
    public:
    vector <int> findMoves(vector <int> start, vector <int> target) {
        vector<int> startMove, targetMove;
        int slot;
        const int n = start.size();
        // move all start's elements to the last slot.
        while (true) {
            for (slot = 0; slot<n-1 && start[slot] == 0; slot++);
            if (slot == n-1)
                break;
            startMove.push_back(slot);
            Amove(start, slot);
        }
        // move all target's elements to the last slot.
        while (true) {
            for (slot = 0; slot<n-1 && target[slot] == 0; slot++);
            if (slot == n-1)
                break;
            targetMove.push_back(Amove(target, slot)+n);
        }
        reverse(targetMove.begin(), targetMove.end());
        startMove.insert(startMove.end(), targetMove.begin(), targetMove.end());
        return startMove;
    }
};
