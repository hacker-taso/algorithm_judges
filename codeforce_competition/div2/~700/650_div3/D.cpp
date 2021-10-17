#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;

string s;
int m;
vector<int> arr;


string solve() {
    int chCnt[26] = {0};
    for (int i=0; i<s.size(); i++) {
        chCnt[s[i]-'a'] += 1;
    }

    stack<int> zeroIdxs;
    vector<char> t(m);
    int usedMax = 26;
    while (true) {
        for (int i=0; i<arr.size(); i++) {
            if (arr[i] == 0)
                zeroIdxs.push(i);
        }
        if (zeroIdxs.empty())
            break;
        int zeroCnt = zeroIdxs.size();
        char c = '?';
        for (int i=usedMax-1; 0<=i; i--) {
            if (zeroCnt <= chCnt[i]) {
                c = (char)(i + 'a');
                usedMax = i;
                break;
            }
        }
        while (!zeroIdxs.empty()) {
            int zeroIdx = zeroIdxs.top(); zeroIdxs.pop();
            t[zeroIdx] = c;
            for (int i=0; i<arr.size(); i++) {
                if (arr[i] == 0) {
                    arr[i] = -1;
                    continue;
                }
                arr[i] -= abs(zeroIdx-i);
            }
        }
    }

    string t_str(t.begin(), t.end());
    return t_str;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> s;
        cin >> m;
        arr = vector<int>(m);
        for (int j=0; j<m; j++)
            cin >> arr[j];
        cout << solve() << endl;
    }
}
