#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
vector<int> values, cnts;

long long solve() {
    long long ret = 0;
    sort(values.begin(), values.end());
    sort(cnts.begin(), cnts.end());
    int valueL = 0, valueR = values.size()-1;
    int cntL = 0, cntR = cnts.size() - 1;
    // cnt == 1 처리
    for (; cntL<cnts.size(); cntL++) {
        if (cnts[cntL] == 1) {
            ret += ((long long)values[valueR]) * 2;
            valueR--;
        } else {
            break;
        }
    }
    // 나머지 처리. 가장 큰 수 1개, cnt-1개의 가장 작은 수 할당.
    for (; cntL <= cntR; cntR--) {
        ret += values[valueR]; // 가장 큰 수.
        valueR--;
        ret += values[valueL]; // 가장 작은 수
        for (int i=0; i<cnts[cntR]-1; i++) {
            valueL++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    string s;
    for (int i=0; i<t; i++) {
        cin >> n >> k;
        values = vector<int>(n);
        cnts = vector<int>(k);
        for (int j=0; j<n; j++)
            cin >> values[j];
        for (int j=0; j<k; j++)
            cin >> cnts[j];
        cout << solve() << endl;
    }
}
