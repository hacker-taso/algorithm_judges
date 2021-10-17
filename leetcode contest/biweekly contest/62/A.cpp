class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ret(m, vector<int>(n));
        if (m*n != original.size())
            return {};
        for (int y=0; y<m; y++) {
            for (int x=0; x<n; x++) {
                ret[y][x] = original[y*n + x];
            }
        }
        return ret;
    }
};