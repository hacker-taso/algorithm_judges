// Start at 01:37AM Feb 22, 2018
// End at 02:25AM Feb 22, 2018
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;

int adjMat[101][101];
long long minDist[101][101];
int N, M;
// minDist, a, b
vector<pair<int, pair<int, int> > > cond;
int main() {
    memset(adjMat, 0, sizeof(adjMat));
    for (int i=0; i<101; i++) {
        for (int j=0; j<101; j++) {
            if (i==j) minDist[i][j] = 0;
            else minDist[i][j] = 0x78901234;
        }
    }
    int a,b,c;
    cin >> N >> M;
    cond = vector<pair<int, pair<int, int> > >();
    for (int i=0; i<M; i++) {
        cin >> a>>b>>c;
        cond.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(cond.begin(), cond.end());
    int edgeCnt = 0;
    for (int i=0; i<M; i++) {
        int a = cond[i].second.first;
        int b = cond[i].second.second;
        int distCond = cond[i].first;
        bool sat = false;
        for (int k=1; k<=N; k++) {
            if (minDist[a][k]+minDist[k][b] < distCond) {
                cout << -1 <<endl;
                return 0;
            }
            if (minDist[a][k]+minDist[k][b] == distCond) {
                sat = true;
                break;
            }
        }
        if (!sat) {
            adjMat[a][b] = (adjMat[b][a] = distCond);
            minDist[a][b] = (minDist[b][a] = distCond);
            edgeCnt++;
            for (int j=1; j<=N; j++) {
                for (int k=1; k<=N; k++)
                    minDist[j][k] = min(minDist[j][a]+minDist[a][k], minDist[j][k]);
            }
        }
    }
    for (int i=1; i<=N; i++) {
        bool updated = false;
        for (int j=i+1; j<=N; j++) {
            if (0x78901234<=minDist[i][j]) {
                adjMat[i][j] = adjMat[j][i] = 1000000;
                minDist[i][j] = minDist[j][i] = 1000000;
                edgeCnt++;
                updated = true;
                break;
            }
        }
        if (!updated) continue;
        for (int j=1; j<=N; j++) {
            for (int k=1; k<=N; k++)
                minDist[j][k] = min(minDist[j][i]+minDist[i][k], minDist[j][k]);
        }
    }
    cout << edgeCnt <<endl;
    for (int i=1; i<=N; i++) {
        for (int j=i; j<=N; j++) {
            if (adjMat[i][j] != 0) {
                cout << i << " " << j << " " << adjMat[i][j] <<endl;
            }
        }
    }
}
