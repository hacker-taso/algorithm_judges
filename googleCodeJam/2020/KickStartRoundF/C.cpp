#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
using namespace std;
int S, meY, meX, youY, youX;
bool adjMat[50][50]; // true: can move

int toNode(int y, int x) {
    y = y-1;
    x = x-1;
    return y*y + x;
}

void setCell(int y, int x, bool val) {
    if (1 <= x-1) {
        adjMat[toNode(y, x)][toNode(y, x-1)] = val;
        adjMat[toNode(y, x-1)][toNode(y, x)] = val;
    }
    if (x+1 <= 2*y-1) {
        adjMat[toNode(y, x)][toNode(y, x+1)] = val;
        adjMat[toNode(y, x+1)][toNode(y, x)] = val;
    }
    if (x%2 == 0 && 1<=y-1){
        adjMat[toNode(y, x)][toNode(y-1, x-1)] = val;
        adjMat[toNode(y-1, x-1)][toNode(y, x)] = val;
    }
    if (y+1 <=S && x%2 ==1){
        adjMat[toNode(y, x)][toNode(y+1, x+1)] = val;
        adjMat[toNode(y+1, x+1)][toNode(y, x)] = val;
    }
}

void init() {
    memset(adjMat, 0, sizeof(adjMat));
    for (int y=1; y<=S; y++) {
        for (int x=1; x<=2*y-1; x++) {
            setCell(y, x, true);
        }
    }
}

bool canMove(int fromY, int fromX, int y, int x) {
    return (
        (1 <= x && x<=2*y-1 && 1<=y && y<=S) &&
        adjMat[toNode(fromY, fromX)][toNode(y, x)]
    );
}

int getMaxScore(int y1, int x1, int y2, int x2) {
    int maxScore = 0;
    const vector<int> ys = {0, 0, -1, +1};
    const vector<int> xs = {-1, +1, -1, +1};
    vector<int> y1cands, x1cands, y2cands, x2cands;
    for (int i=0; i<ys.size(); i++) {
        int newY1 = y1+ys[i], newX1 = x1 + xs[i];
        if (canMove(y1, x1, newY1, newX1)) {
            y1cands.push_back(newY1);
            x1cands.push_back(newX1);
        }
    }
    setCell(y1, x1, false);

    int ret = 0;
    if (y1cands.size() == 0) {
        for (int i=0; i<ys.size(); i++) {
            int newY2 = y2+ys[i], newX2 = x2 + xs[i];
            if (canMove(y2, x2, newY2, newX2)) {
                y2cands.push_back(newY2);
                x2cands.push_back(newX2);
            }
        }
        if (y2cands.size() == 0) {
            setCell(y1, x1, true);
            return 0;
        }
        setCell(y2, x2, false);
        int minScore = numeric_limits<int>::max();
        for (int i=0; i<y2cands.size(); i++) {
            int newY2 = y2cands[i], newX2 = x2cands[i];
            minScore = min(getMaxScore(y1, x1, newY2, newX2) - 1, minScore);
        }
        ret = minScore;
    }
    else  {
        int maxScore = numeric_limits<int>::min();
        for (int i=0; i<y1cands.size(); i++) {
            int newY1 = y1cands[i], newX1 = x1cands[i];
            setCell(newY1, newX1, false);
            for (int j=0; j<ys.size(); j++) {
                int newY2 = y2+ys[j], newX2 = x2 + xs[j];
                if (canMove(y2, x2, newY2, newX2)) {
                    y2cands.push_back(newY2);
                    x2cands.push_back(newX2);
                }
            }
            setCell(y2, x2, false);
            setCell(newY1, newX1, true);
            if (y2cands.size() == 0) {
                maxScore = max(getMaxScore(newY1, newX1, y2, x2) + 1, maxScore);
            } else{
                int minScore = numeric_limits<int>::max();
                for (int j=0; j<y2cands.size(); j++) {
                    int newY2 = y2cands[j], newX2 = x2cands[j];
                    minScore = min(minScore, getMaxScore(newY1, newX1, newY2, newX2));
                }
                maxScore = max(maxScore, minScore);
            }
            setCell(y2, x2, true);
        }
        ret = maxScore;
    }
    setCell(y1, x1, true);
    setCell(y2, x2, true);
    return ret;
}


int solve() {
    return getMaxScore(meY, meX, youY, youX);
}

// 최대 S^2 node. -> 6^2 == 36 node. 최대 3방향 이동가능. 온 방향으로는 못가므로 2방향. 2^36
int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        int y1, x1, y2, x2, C;
        cin >> S >> meY >> meX >> youY >> youX >> C;
        init();
        for (int j = 0; j < C; j++) {
            cin >> y1 >> x1;
            setCell(y1, x1, false);
        }
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}
