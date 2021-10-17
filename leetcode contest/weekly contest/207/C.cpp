// max: 4^29 -> long long can accomodate it;
#define MOD 1000000007
class Solution {
public:
    long long int maxDp[16][16];
    long long int minDp[16][16];
    int maxProductPath(vector<vector<int>>& grid) {
        int ySize = grid.size();
        int xSize = grid[0].size();
        maxDp[0][0] = minDp[0][0] = grid[0][0];
        for (int y=1; y<ySize; y++)
            maxDp[y][0] = minDp[y][0] = maxDp[y-1][0] * grid[y][0];
        for (int x=1; x<xSize; x++)
            maxDp[0][x] = minDp[0][x] = maxDp[0][x-1] * grid[0][x];
        
        const vector<vector<int>> dirs = {{-1, 0}, {0, -1}};
        for (int y=1; y<ySize; y++) {
            for (int x=1; x<xSize; x++) {
                bool first = true;
                for (int i=0; i<dirs.size(); i++) {
                    long long int maxProd = maxDp[y+dirs[i][0]][x+dirs[i][1]] * grid[y][x];
                    long long int minProd = minDp[y+dirs[i][0]][x+dirs[i][1]] * grid[y][x];
                    if (first) {
                        first = false;
                        maxDp[y][x] = max(maxProd, minProd);
                        minDp[y][x] = min(maxProd, minProd);
                    } else {
                        maxDp[y][x] = max(max(maxProd, minProd), maxDp[y][x]);
                        minDp[y][x] = min(min(maxProd, minProd), minDp[y][x]);
                    }
                }
            }
        }
        long long int res = max(maxDp[ySize-1][xSize-1], minDp[ySize-1][xSize-1]);
        if (res < 0)
            return -1;
        return res % MOD;
    }
};