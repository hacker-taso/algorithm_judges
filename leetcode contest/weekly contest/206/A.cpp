class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ret = 0;
        vector<int> cols(mat.size(), 0);
        vector<int> rows(mat[0].size(), 0);
        for (int y=0; y<cols.size(); y++) {
            for (int x=0; x<rows.size(); x++)
                if (mat[y][x] == 1) {
                    cols[y]++;
                    rows[x]++;
                }
        }
        
        for (int y=0; y<cols.size(); y++) {
            if (cols[y] != 1)
                continue;
            for (int x=0; x<rows.size(); x++)
                if (cols[y] == 1 && rows[x] == 1) {
                    ret++;
                    break;
                }
        }
        return ret;
    }
};