class Solution {
public:
    vector<int> pairsDict;
    vector<vector<int>> prefDict;
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        pairsDict = vector<int>(n);
        for (int i=0; i<pairs.size(); i++) {
            pairsDict[pairs[i][0]] = pairs[i][1];
            pairsDict[pairs[i][1]] = pairs[i][0];
        }
        prefDict = vector<vector<int>>(n, vector<int>(n));
        for (int x=0; x<n; x++) {
            for (int j=0; j<preferences[x].size(); j++) {
                int y = preferences[x][j];
                prefDict[x][y] = -j; // low index -> high pref
            }
        }
        int unhappyCounts = 0;
        for (int i=0; i<pairs.size(); i++) {
            int y = pairs[i][0];
            int x = pairs[i][1];
            unhappyCounts += checkUnhappy(y, x, preferences);
            unhappyCounts += checkUnhappy(x, y, preferences);
        }
        return unhappyCounts;
    }
    bool checkUnhappy(int y, int x, vector<vector<int>>& preferences) {
        for (int j=0; j<preferences[x].size(); j++) {
            if (preferences[x][j] == y)
                break;
            int u = preferences[x][j];
            int v = pairsDict[u];
            if (prefDict[u][v]<prefDict[u][x])
                return true; // x unhappy
        }
        return false;
    }
};