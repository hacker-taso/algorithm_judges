// Start at 02:45AM Feb 17, 2018
// end at 03:31AM Feb 17, 2018
// Retrospection:
// The reason why I took a lot of time:
//  I was confused row with column, especially when transforming grid idx to vector idx.
//  should be numCol * rowNum +col but I wrote nulRow*rowNum+col.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class GridSortMax {
private:
    int getIdx(vector<int>& grid, int val) {
        return distance(grid.begin(), find(grid.begin(), grid.end(), val));
    }
    int getGridIdx(int m, int row, int col) {
        return m*row + col;
    }
    public:
    string findMax(int n, int m, vector <int> grid) {
        vector<bool> rowComplete(n, false);
        vector<bool> colComplete(m, false);
        for (int i=1; i<=n*m; i++) {
            int idx = getIdx(grid, i);
            int row = idx/m;
            int col = idx%m;
            int goalRow = (i-1)/m;
            int goalCol = (i-1)%m;
            if ((rowComplete[goalRow] || rowComplete[row]) && row!=goalRow) continue;
            if ((colComplete[goalCol] || colComplete[col]) && col!=goalCol) continue;
            if (row!= goalRow)
                for (int j=0; j<m; j++)
                    swap(grid[getGridIdx(m,row,j)], grid[getGridIdx(m,goalRow,j)]);
            if (col!=goalCol)
                for (int j=0; j<n; j++)
                    swap(grid[getGridIdx(m,j,col)], grid[getGridIdx(m,j, goalCol)]);
            rowComplete[goalRow] = true;
            colComplete[goalCol] = true;
        }
        string sim = "";
        for (int i=0; i<grid.size(); i++) {
            sim += to_string(grid[i] == (i+1));
        }
        return sim;
    }
};
