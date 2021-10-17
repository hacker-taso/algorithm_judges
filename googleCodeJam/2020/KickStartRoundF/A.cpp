#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, maxAmt;
vector<int> wants;

vector<int> solve() {
    vector<int> tryCnt(N);
    for (int i=0; i<N; i++)
        tryCnt[i] = wants[i] / maxAmt + ((wants[i] % maxAmt) != 0);
    priority_queue<pair<int,int>> pq;
    for (int i=0; i<N; i++)
        pq.push(make_pair(-tryCnt[i], -i));
    vector<int> ret;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        ret.push_back(-p.second + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> maxAmt;
        wants = vector<int>(N);
        for (int j = 0; j < N; j++)
            cin >> wants[j];
        vector<int> sol = solve();
        cout << "Case #" << i+1 << ": ";
        for (int j=0; j<sol.size(); j++)
            if (j == 0)
                cout << sol[j];
            else
                cout << " " << sol[j];
        cout << endl;
    }
}