#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
vector<int> a, b;
int maxB = 0;
int maxA = 0;

long long solve() {
    if (n == 1)
        return maxA;
    long long sum = 0;
    long long maxSum = 0;
    int idx = 0;
    for (int i=0; i<m; i++) {
        sum = a[i] + (n-1)* b[i];
        if (maxSum < sum) {
            maxSum = sum;
            idx = i;
        }
    }
    sort(a.begin(), a.end());
    for (int i=a.size()-1; 0<=i; i--)
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        a = vector<int>(m);
        b = vector<int>(m);
        sum = 0;
        maxA = 0;
        maxB = 0;
        for (int j=0; j<m; j++) {
            cin >> a[j] >> b[j];
            sum += a[j];
            maxA = max(a[j], maxA);
            maxB = max(b[j], maxB);
        }
        cout << solve() << endl;
    }
}
