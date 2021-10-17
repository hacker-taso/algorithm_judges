#include<iostream>
#include<algorithm>
using namespace std;
const string GOAL="abacaba";



void solve(string s) {
    int pos = s.find(GOAL);
    if (pos != string::npos) {
        pos = s.find(GOAL, pos+1);
        if (pos != string::npos) {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
        replace(s.begin(), s.end(), '?', 'z');
        cout << s << endl;
        return;
    }
    for (int i=0; i<s.size(); i++) {
        for (int j=0; j<GOAL.size() && i+j<s.size(); j++) {
            if (s[i+j] != '?' && s[i+j] != GOAL[j])
                break;
            if (j == GOAL.size()-1) {
                string res = s.substr(0, i);
                res += GOAL;
                res += s.substr(i+j+1);
                replace(res.begin(), res.end(), '?', 'z');
                int pos = res.find(GOAL);
                if (pos != string::npos) {
                    pos = res.find(GOAL, pos+1);
                    if (pos != string::npos) {
                        continue;
                    }
                    cout << "Yes" << endl;
                    cout << res << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    string s;
    for (int i=0; i<t; i++) {
        cin >> n;
        cin >> s;
        solve(s);
    }
}
