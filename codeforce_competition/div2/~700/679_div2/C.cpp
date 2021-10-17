#include<iostream>
#include<vector>
#include<limits>
using namespace std;

vector<int> as;
vector<int> bs;

int solve() {
    sort(bs.begin(), bs.end());
    int biggest = bs.back(), smallest = bs.front();
    int ret = numeric_limits<int>::max();
    for (int i=0; i<6; i++) {
        int fromBig = biggest - as[i];
        for (int j=0; j<6; j++) {
            int fromSmall = smallest - as[j];
            ret = min(ret, abs(fromBig-fromSmall));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    as.resize(6);
    for (int i=0; i<6; i++)
        cin >> as[i];
    int n;
    cin >> n;
    bs.resize(n);
    for (int i=0; i<n; i++)
        cin >> bs[i];
    cout << solve() << endl;
}
