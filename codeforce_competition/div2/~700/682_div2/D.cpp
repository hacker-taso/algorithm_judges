#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
int n;

int getZeroCnt(int digitIdx) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += (arr[i] >> digitIdx) == 0;
    }
    return cnt;
}

// 2개인 bit는 1개인 bit로 변환됨. ex) 0 0 1 -> 1 1 1
// -> 2개씩 줄일 수 있음. -> 짝수개인 수를 홀수개인 수로 변환.
// ex) 1 0 0 0 1 -> 0 0 0 0 0
// 0과 1 둘다 홀수개인 경우 변환 불가.
// 참고로, 3개의 bit가 동일 한 경우 변하지않음. ex) 1 1 1 -> 1 1 1, ex2) 0 0 0 -> 0 0 0 
void solve() {
    vector<vector<int>> res;
    // check
    for (int i=0; i<30; i++) { // 10**9: 최대 30bit
        int zeroCnt = getZeroCnt(i);
        int oneCnt = n - zeroCnt;
        if (zeroCnt%2 == 1 && oneCnt%2 == 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << res.size() << endl;
    for (int i=0; i<res.size(); i++)
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    arr.resize(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    solve();
}
