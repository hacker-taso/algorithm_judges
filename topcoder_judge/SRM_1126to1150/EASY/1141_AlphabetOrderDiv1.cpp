// Start at 06:19PM Feb 17, 2018
// end at ?PM Feb 17, 2018 (about 2 hours taken)
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class AlphabetOrderDiv1 {
private:
    bool adjMat[26][26];
    bool visited[26];
    int toIdx(char c) {
        return c-'a';
    }
    void topoSort(int from, vector<int>& res) {
        if (visited[from]) return;
        visited[from] = true;
        for (int to=0; to<26; to++) {
            if (adjMat[from][to]) {
                topoSort(to, res);
            }
        }
        res.push_back(from);
    }
    public:
    string isOrdered(vector <string> words) {
        memset(adjMat, 0, sizeof(adjMat));
        for (int i=0; i<words.size(); i++) {
            for (int j=1; j<words[i].size(); j++) {
                adjMat[toIdx(words[i][j-1])][toIdx(words[i][j])] = true;
            }
        }
        memset(visited, 0, sizeof(visited));
        for (int i=0; i<26; i++) {
            if (visited[i]) continue;
            vector<int> res;
            topoSort(i, res);
            reverse(res.begin(), res.end());
            for (int j=0; j<res.size(); j++) {
                for (int k=j+1; k<res.size(); k++) {
                    if (adjMat[res[k]][res[j]]) return "Impossible";
                }
            }
        }
        return "Possible";
    }
};
