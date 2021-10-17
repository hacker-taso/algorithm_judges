#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

int n;
vector<int> arr;
vector<vector<int>> posArr;
void solve() {
    for (int i=0; i<n; i++)
        posArr[arr[i]].push_back(i);
    priority_queue<pair<int,int>> pq;
    for (int i=1; i<=n; i++) {
        if (posArr[i].empty())
            continue;
        int minK = posArr[i][0] + 1;
        for (int j=1; j<posArr[i].size(); j++) {
            // distance from front
            minK = max(minK, posArr[i][j] - posArr[i][j-1]);
        }
        minK = max(minK, n - posArr[i].back());
        pq.push(make_pair(-minK, -i));
    }
    int amazing = -1;
    for (int k=1; k<=n; k++) {
        while (!pq.empty()) {
            auto [minK, a] = pq.top();
            minK = -minK, a = -a;
            if (k < minK)
                break;
            pq.pop();
            if (amazing == -1 || a < amazing)
                amazing = a;
        }
        cout << amazing;
        if (k != n)
            cout << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        arr = vector<int>(n);
        for (int j=0; j<n; j++)
            cin >> arr[j];
        posArr = vector<vector<int>>(n+1, vector<int>());
        solve();
    }
}
