#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long targetY, targetX;
vector<long long> costs;
vector<vector<int>> rules = {
    {-1, -1,-1, -1},
    {1, 1, 1, -1},
    {2, 0, 1, -1},
    {2, -1, 0, -1},
    {1, -1, -1, -1},
    {2, 0, -1, -1},
    {2, 1, 0, -1}
};

long long int solve() {
    vector<int> ruleIdxs;
    if (targetY == 0) {
        if (targetX < 0)
            ruleIdxs.push_back(5);
        else
            ruleIdxs.push_back(2);
    } else if (targetX == 0) {
        if (targetY < 0)
            ruleIdxs.push_back(3);
        else
            ruleIdxs.push_back(6);
    } else {
        for (int i=1; i<=6; i++) {
            if ((((rules[i][1] < 0) ^ (targetY < 0)) == 0) || (((rules[i][2] < 0)^(targetX<0)) == 0))
                ruleIdxs.push_back(i);
        }
    }
    sort(ruleIdxs.begin(), ruleIdxs.end());
    long long int ret = 0;
    for (int i=0; i<ruleIdxs.size(); i++) {
        int yMove = rules[ruleIdxs[i]][1], xMove = rules[ruleIdxs[i]][2], cost = rules[ruleIdxs[i]][3];
        int move = min(abs(targetY), abs(targetX));
        if (move == 0)
            move = max(abs(targetX), abs(targetY));
        ret += cost* move;
        targetY -= yMove * move;
        targetX -= xMove * move;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> targetY >> targetX;
        for (int j=1; j<=6; j++)
            cin >> rules[j][3];
        cout << solve() << endl;
    }
}
