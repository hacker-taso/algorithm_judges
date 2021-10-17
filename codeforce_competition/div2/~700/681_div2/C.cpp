#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> delivery;
vector<int> walk;

long long int solve() {
    vector<vector<int>> vecs;
    for (int i=0; i<delivery.size(); i++) {
        vecs.push_back({delivery[i], -walk[i]});
    }
    sort(vecs.begin(), vecs.end());
    long long int totalWalk = 0;
    long long int deliveryTime = vecs.back()[0];
    for (int i=vecs.size()-1; 1<=i; i--) {
        int w = -vecs[i][1];
        long long int nextTotalWalk = totalWalk + w;
        long long int nextDeliveryTime = vecs[i-1][0];
        long long int nextVal = max(nextTotalWalk, nextDeliveryTime);
        if (max(deliveryTime, totalWalk)<nextVal) {
            return max(deliveryTime, totalWalk);
        }
        totalWalk = nextTotalWalk;
        deliveryTime = nextDeliveryTime;
    }
    int w = -vecs[0][1];
    long long int nextTotalWalk = totalWalk + w;
    long long int nextVal = nextTotalWalk;
    long long int prevVal = max(totalWalk, deliveryTime);
    return min(prevVal, nextVal);
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        delivery.resize(n);
        walk.resize(n);
        for (int j=0; j<n; j++)
            cin >> delivery[j];
        for (int j=0; j<n; j++)
            cin >> walk[j];
        cout << solve() << endl;
    }
}
