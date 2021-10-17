#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N;
vector<int> arr;

vector<int> partialSum(const vector<int>& a) {
    vector<int> ret(a.size());
    ret[0] = a[0];
    for (int i=1; i<a.size(); i++)
        ret[i] = ret[i-1] + a[i];
    return ret;
}

int rangeSum(const vector<int>& psum, int a, int b) {
    if (a==0) return psum[b];
    return psum[b] - psum[a-1];
}

long long solve() {
    long long cnt = 0;
    vector<int> psum = partialSum(arr);
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            int rs = rangeSum(psum, i, j);
            if (rs < 0)
                continue;
            int sqr = sqrt(rs);
            if (sqr*sqr == rs) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N;
        arr = vector<int>(N);
        for (int j=0; j<N; j++)
            cin >> arr[j];
        long long sol = solve();
        cout << "Case #" << i+1 << ": " << sol << endl;
    }
}