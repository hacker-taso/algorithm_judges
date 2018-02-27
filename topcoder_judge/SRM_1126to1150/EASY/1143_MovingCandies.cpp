// Retry
// a comment in http://codeforces.com/blog/entry/49002
// Start at 11:25PM Feb 20, 2018
// it took about 2 hours.
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#define EMPTY '.'
#define CANDY '#'
using namespace std;

// there, weight
vector<pair<int,int> > adjList[400];
// col, row, len
int dp[20][20][401];

class MovingCandies {
private:
    int candyCnt;
    int colLen;
    int rowLen;
    int toIdx(int y, int x) {
        return y*rowLen+x;
    }
    pair<int,int> toYX(int idx) {
        return make_pair(idx/colLen, idx%colLen);
    }
    int findMinPath(int initial) {
        for (int i=0; i<20; i++)
            for (int j=0; j<20; j++)
                for (int k=0; k<401; k++)
                    dp[i][j][k]=1000000;
        // -weight, len, nodeIdx
        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push(make_pair(-initial, make_pair(1, 0)));
        while(!pq.empty()) {
            pair<int, pair<int, int> > here = pq.top();
            pq.pop();
            int distCand = -here.first;
            int curLen = here.second.first;
            pair<int, int> hereNode = toYX(here.second.second);
            if (candyCnt<curLen) continue;
            if (dp[hereNode.first][hereNode.second][curLen]<=distCand) continue;
            dp[hereNode.first][hereNode.second][curLen] = distCand;
            for (int i=0; i<adjList[here.second.second].size(); i++) {
                int thereNode = adjList[here.second.second][i].first;
                int thereWeight = adjList[here.second.second][i].second;
                pq.push(make_pair(-(distCand + thereWeight), make_pair(curLen+1, thereNode)));
            }
        }
        int minCandy = 10000000;
        for (int i=0; i<=candyCnt; i++) {
            minCandy = min(dp[rowLen-1][colLen-1][i], minCandy);
        }
        return minCandy;
    }
    public:
    int minMoved(vector <string> t) {
        colLen = t.size();
        rowLen = t[0].size();
        candyCnt = 0;
        for (int i=0; i<t.size(); i++)
            for (int j=0; j<t[0].size(); j++)
                candyCnt+=(t[i][j]==CANDY);
        if (candyCnt<colLen+rowLen-1) return -1;
        for (int y=0; y<colLen; y++) {
            for (int x=0; x<rowLen; x++) {
                int idx = toIdx(y, x);
                if (0<y) adjList[idx].push_back(make_pair(toIdx(y-1, x), t[y-1][x] != CANDY));
                if (0<x) adjList[idx].push_back(make_pair(toIdx(y, x-1), t[y][x-1] != CANDY));
                if (y<colLen-1) adjList[idx].push_back(make_pair(toIdx(y+1, x), t[y+1][x] != CANDY));
                if (x<rowLen-1) adjList[idx].push_back(make_pair(toIdx(y, x+1), t[y][x+1] != CANDY));
            }
        }
        return findMinPath(t[0][0] != CANDY);
    }
};
