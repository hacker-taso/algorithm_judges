#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;
int n;
vector<string> ts;

ull solve() {
    ull noise = 0;
    for (int i=0; i<n; i++) {
        const string& s = ts[i];
        int numS = 0;
        for (int j=0; j<s.size(); j++) {
            if (s[j] == 's')
                numS++;
            else
                noise += numS;
        }
    }
    // number of h, -number of s
    vector<pair<ull, pair<int, int> > > pairs;
    ull totalNumH = 0;
    for (int i=0; i<n; i++) {
        const string& s = ts[i];
        int numS = 0;
        int numH = 0;
        for (int j=0; j<s.size(); j++) {
            if (s[j] =='s') numS++;
            else numH++;
        }
        totalNumH += numH;
        pairs.push_back(make_pair((double)numH/numS, make_pair(numH, numS)));
    }
    sort(pairs.begin(), pairs.end());
    ull coef = totalNumH;
    for (int i=0; i<n; i++) {
        coef-=pairs[i].second.first;
        noise += (pairs[i].second.second)*coef;
    }
    return noise;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ts = vector<string>(n);
    for (int i=0; i<n; i++) {
        cin >> ts[i];
    }
    cout << solve() << endl;
}
