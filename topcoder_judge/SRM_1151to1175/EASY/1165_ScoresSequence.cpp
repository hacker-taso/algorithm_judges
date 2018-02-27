// Retry
// This problem took much time for me (maybe 6~10 hours?) because I started from scratch several time.
// Retrospection:
// 1. I thought about greedy algorithm but I couldn't prove the validity.
//  I found editorial solver but I think the solver is incorrect.
// 2. Even after I found out a method using network flow, I wrongly made the model. (vertices with Ain and Aout)
// 3. Solving network flow was also diffcult because this one is neither bipartite matching and a network flow
//  which can be solved just by setting adjMat[numVertices][numVertices] because numVertices are about 10000.
//  I think using mutual recursive was a good choice.
#include<iostream>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

class ScoresSequence {
private:
    int edgeMatch[10000];
    bool adjMat[100][100];
    int capacity[100];
    int flow[100];
    int size;
    void init(vector <int>& s) {
        size = s.size();
        memset(edgeMatch, -1, sizeof(edgeMatch));
        memset(flow, 0, sizeof(flow));
        memset(capacity, 0, sizeof(capacity));
        memset(adjMat, 0, sizeof(adjMat));
        for (int i=0; i<size; i++) {
            capacity[i] = s[i];
        }
    }
    vector<bool> edgeVisited;
    vector<bool> vertexVisited;
    bool fromEdge(int e) {
        if (edgeVisited[e]) return false;
        edgeVisited[e] = true;
        int v1 = e%size;
        int v2 = e/size;
        if (edgeMatch[e] == v1) {
            if (fromVertex(v2)) {
                edgeMatch[e] = v2;
                return true;
            }
        } else if (edgeMatch[e] == v2) {
            if (fromVertex(v1)) {
                edgeMatch[e] = v1;
                return true;
            }
        } else {
            if (fromVertex(v1)) {
                edgeMatch[e] = v1;
                return true;
            } else if (fromVertex(v2)) {
                edgeMatch[e] = v2;
                return true;
            }
        }
        return false;
    }
    bool fromVertex(int v) {
        if (vertexVisited[v]) return false;
        vertexVisited[v] = true;
        if (flow[v] < capacity[v]) {
            flow[v]+=1;
            return true;
        }
        for (int i=0; i<size; i++) {
            if (i==v) continue;
            int small = min(i, v);
            int big = max(i, v);
            if (edgeMatch[big*size+small]==v && fromEdge(big*size+small)) {
                return true;
            }
        }
        return false;
    }
    void solveFlow() {
        for (int i=0; i<size; i++){ 
            for (int j=0; j<size; j++) {
                if (i<=j) continue;
                edgeVisited = vector<bool>(size*size, 0);
                vertexVisited = vector<bool>(size, 0);
                fromEdge(i*size+j);
            }
        }
    }
    public:
    int count(vector <int> s) {
        init(s);
        solveFlow();
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                if (i<j) continue;
                if (i==j) {
                    adjMat[i][j] = 1;
                    continue;
                }
                if (edgeMatch[i*size+j]==i) {
                    adjMat[i][j] = 1;
                } else if (edgeMatch[i*size+j]==j){
                    adjMat[j][i] = 1;
                }
            }
        }
        for (int k=0; k<s.size(); k++) {
            for (int i=0; i<s.size(); i++) {
                for (int j=0; j<s.size(); j++) {
                    adjMat[i][j] = adjMat[i][j] || (adjMat[i][k] && adjMat[k][j]);
                }
            }
        }
        int cnt = 0;
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<s.size(); j++) {
                cnt += adjMat[i][j];
            }
        }
        return cnt;
    }
};
 