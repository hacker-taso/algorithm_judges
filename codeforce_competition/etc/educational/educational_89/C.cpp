#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int mat[30][30];

int solve() {
    int ret = 0;
    int cnt[2] = {0};
    for (int xySum=0; xySum<(n+m-1)/2; xySum++) {
        cnt[0] = 0;
        cnt[1] = 0;
        for (int y=0; y<=xySum && y<n; y++) {
            int x = xySum - y;
            cnt[mat[y][x]]++;
            cnt[mat[n-y-1][m-x-1]]++;
        }
        if (cnt[0] < cnt[1])
            ret += cnt[0];
        else
            ret += cnt[1];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        for (int j=0; j<n; j++) {
            for (int k=0; k<m; k++)
                cin >> mat[j][k];
        }
        cout << solve() << endl;
    }
}
