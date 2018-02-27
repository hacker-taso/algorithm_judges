// start from 11:49PM, Jan 14, 2018
// complete at 1:04AM, Jan 15, 2018
// It took too much time for this problem.
// The mistake I made was not carefully reading the problem.
// First time, I thought I need to check all consecutive sequence.
// But I only needed to check consecutive pairs.
// Also, I had trouble in checking sequences because
// it is circular queue.
#include<iostream>
#include<vector>
using namespace std;
class CircleGame {
    public:
    int cardsLeft(string deck) {
        vector<int> seq(deck.size());
        int len = deck.size();
        for (int i=0; i<len; i++) {
            if (deck[i] == 'A') seq[i] = 1;
            else if (deck[i] == 'T') seq[i] = 10;
            else if (deck[i] == 'J') seq[i] = 11;
            else if (deck[i] == 'Q') seq[i] = 12;
            else if (deck[i] == 'K') seq[i] = 13;
            else seq[i] = deck[i]-'0';
        }
        if (len == 0) return 0;
        while (true) {
            int len = seq.size();
            int found = false;
            for (int i=0; i<seq.size(); i++) {
                if (seq[i] == 13) {
                    seq.erase(seq.begin()+i);
                    found = true;
                    break;
                }
                else if (1<len && seq[i]+seq[(i+1)%len] == 13) {
                    if (i==len-1) {
                        seq.erase(seq.begin()+i);
                        seq.erase(seq.begin());
                    } else {
                        seq.erase(seq.begin()+i+1);
                        seq.erase(seq.begin()+i);
                    }
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        return seq.size();
    }
};
