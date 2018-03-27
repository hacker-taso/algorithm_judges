#include <iostream>
#include<vector>
using namespace std;

int main() {
    int numRow, numCol;
    cin >> numRow >> numCol;
    vector< vector<int> > mat(numRow, vector<int>(numCol));
    for (int y=0; y<numRow; y++) {
        for (int x=0; x<numCol; x++) {
            cin >> mat[y][x];
        }
    }
    vector<int> rowPoints(numRow, 0);
    rowPoints[0] = mat[0][0] + mat[0][numCol-1];
    rowPoints[numRow-1] = mat[numRow-1][0] + mat[numRow-1][numCol-1];
    for (int x=1; x<numCol-1; x++) {
        rowPoints[0] += mat[0][x]*2;
        rowPoints[numRow-1] += mat[numRow-1][x]*2;
    }
    int bigTopBottm = max(rowPoints[0], rowPoints[numRow-1]);
    for (int y=1; y<numRow-1; y++) {
        rowPoints[y] = (mat[y][0] + mat[y][numCol-1])*2;
        for (int x=1; x<numCol-1; x++)
            rowPoints[y] += mat[y][x]*4;
    }
    vector<int> colPoints(numCol, 0);
    colPoints[0] = mat[0][0] + mat[numRow-1][0];
    colPoints[numCol-1] = mat[0][numCol-1] + mat[numRow-1][numCol-1];
    for (int y=1; y<numRow-1; y++) {
        colPoints[0] += mat[y][0]*2;
        colPoints[numCol-1] += mat[y][numCol-1]*2;
    }
    int bigLeftRight = max(colPoints[0], colPoints[numCol-1]);
    for (int x=1; x<numCol-1; x++) {
        colPoints[x] = (mat[0][x]+mat[numRow-1][x])*2;
        for (int y=1; y<numRow-1; y++)
            colPoints[x] += mat[y][x]*4;
    }
    int smallestRowPoint = 0x76543210;
    for (int y=1; y<numRow-1; y++) {
        smallestRowPoint = min(smallestRowPoint, rowPoints[y]);
    }
    int smallestColPoint = 0x76543210;
    for (int x=1; x<numCol-1; x++) {
        smallestColPoint = min(smallestColPoint, colPoints[x]);
    }
    int incrVal = 0;
    if (smallestRowPoint != 0x76543210 && 0<-smallestRowPoint/2 + bigTopBottm ) {
        incrVal = -smallestRowPoint/2 + bigTopBottm;
    }
    if (smallestColPoint != 0x76543210 && 0<-smallestColPoint/2 + bigLeftRight &&
     incrVal < -smallestColPoint/2 + bigLeftRight) {
        incrVal = -smallestColPoint/2 + bigLeftRight;
    }
    int beauty = 0;
    for (int i=0; i<numCol; i++) {
        beauty += colPoints[i];
    }
    beauty += incrVal;
    cout << beauty <<endl;
}
