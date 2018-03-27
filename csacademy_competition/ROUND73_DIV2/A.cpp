#include <iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i=0; i<n; i++)
        cin >> seq[i];
    int costs[3];
    for (int goal=0; goal<3; goal++) {
        costs[goal] = 0;
        vector<int> seqCopy = seq;
        for (int i=0; i<n; i++) {
            if (seqCopy[i] == goal) continue;
            while (seqCopy[i] != goal) {
                seqCopy[i] = (seqCopy[i]+1)%3;
                costs[goal]++;
            }
        }
    }
    int sol = min(costs[0],min(costs[1],costs[2]));
    cout << sol << endl;
    return 0;
}