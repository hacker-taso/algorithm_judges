#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define MOD 1000000007
int cache[2000001];
bool cache2[2000001];

int n;

pair<int, bool> getCnt(int level) {
    if (level <= 2)
        return make_pair(0, false);
    if (level == 3)
        return make_pair(4, true);
    else {
        if (cache[level] != -1)
            return make_pair(cache[level], cache2[level]);
        pair<int, bool> c = getCnt(level-1);
        pair<int, bool> lr = getCnt(level-2);
        int cnt = (c.first + (unsigned long long)lr.first*2) % MOD;
        if (!c.second && !lr.second) {
            cache[level] = ((unsigned long long)cnt+4)%MOD;
            cache2[level] = true;
            return make_pair(cache[level], true);
        }
        cache[level] = cnt;
        cache2[level] = false;
        return make_pair(cnt, false);
    }
}

int solve() {
    pair<int, bool> ret = getCnt(n);
    return ret.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        memset(cache2, 0, sizeof(cache2));

        cout << solve() << endl;
    }
}
