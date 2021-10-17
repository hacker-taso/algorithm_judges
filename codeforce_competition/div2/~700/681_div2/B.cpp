#include<iostream>
#include<vector>
using namespace std;

int a, b;
string mineMap;

int solve() {
    bool beforeZero = true;
    bool isFirst = true;
    int ret = 0;
    int zeroCnt = 0;
    for (int i=0; i<mineMap.size(); i++) {
        if (mineMap[i] == '1') {
            if (isFirst) {
                isFirst = false;
                ret += a;
                beforeZero = false;
                continue;
            }
            if (beforeZero) {
                beforeZero = false;
                int connectCost = zeroCnt * b;
                int activateCost = a;
                ret += min(connectCost, activateCost);
            } else {
                continue;
            }
        } else {
            if (beforeZero) {
                zeroCnt += 1;
            } else {
                beforeZero = true;
                zeroCnt = 1;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        cin >> mineMap;
        cout << solve() << endl;
    }
}
