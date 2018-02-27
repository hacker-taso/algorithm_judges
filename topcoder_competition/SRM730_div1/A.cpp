// Start at 09:00PM Feb 20, 2018
// end at 09:46PM Feb 20, 2018
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    vector<int> children;
};

Node nodes[1005];

class StonesOnATree {
private:
    int maxWeight(vector<int>& w, int r) {
        if (nodes[r].children.empty()) return w[r];
        if (nodes[r].children.size() == 1) {
            return max(w[nodes[r].children[0]]+w[r], maxWeight(w, nodes[r].children[0]));
        }
        return max(w[nodes[r].children[0]]+w[nodes[r].children[1]]+w[r],
            max(maxWeight(w, nodes[r].children[0]), 
            max(maxWeight(w, nodes[r].children[1]), 
                min(w[nodes[r].children[0]]+maxWeight(w, nodes[r].children[1]),
                    w[nodes[r].children[1]]+maxWeight(w, nodes[r].children[0])))));
    }
    public:
    int minStones(vector <int> p, vector <int> w) {
        for (int i=0; i<p.size(); i++) {
            nodes[p[i]].children.push_back(i+1);
        }
        return maxWeight(w, 0);
    }
};
