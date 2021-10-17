#include<iostream>
#include<vector>
using namespace std;

int n, k;
string states;

int solve() {
    int ret = 0;
    int beforeOneIdx = -1;
    for (int i=0; i<n && i<=k; i++)
        if (states[i] == '1') {
            beforeOneIdx = i;
            break;
        }
    if (beforeOneIdx == -1) {
        // i<=k까지 1이 없는 경우 (1을 맨앞에 놓을 수 있음)
        beforeOneIdx = 0;
        ret++;
    }
    for (int i=beforeOneIdx+1; i<n; i++) {
        if (states[i] == '1') {
            beforeOneIdx = i;
            continue;
        }
        if (beforeOneIdx + k+1 + k <= i) {
            // beforeOneIdx + k+1: 다음 1 위치. (beforeOneIdx + k+1) + k까지 0이면.
            beforeOneIdx += k+1;
            ret++;
        }
    }
    if (beforeOneIdx+k+1 <= n-1) // 마지막 체크 (n-1 인덱스에 1 넣을 수 있는지)
        ret++;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> k;
        cin >> states;
        cout << solve() << endl;
    }
}
