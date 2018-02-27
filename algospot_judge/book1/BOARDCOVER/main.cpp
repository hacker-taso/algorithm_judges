#include<iostream>
using namespace std;
int board[20][20];
int H, W;
int LShapeX[4][3] = {{0,1,0}, {0,1,1}, {0,-1,0}, {0,0,1}};
int LShapeY[4][3] = {{0,0,1}, {0,0,1}, {0,1,1}, {0,1,1}};
bool isLShapeInsertable(int y, int x, int shapeIndex) {
	bool insertable = true;
	for(int i=0; i<3; i++) {
		insertable = insertable && (0 <= y + LShapeY[shapeIndex][i]) && (y + LShapeY[shapeIndex][i] < H)
			&& (0 <= x + LShapeX[shapeIndex][i]) && (x + LShapeX[shapeIndex][i] < W)
			&& (board[y + LShapeY[shapeIndex][i]][x + LShapeX[shapeIndex][i]] == 0);
	}
	return insertable;
}
int counter(int checkStart) {
	int x, y, count = 0, currPos = 0;
	for (currPos=checkStart; currPos<H*W; currPos++) {
		x = currPos%W;
		y = currPos/W;
		if (board[y][x] == 0) {
			break;
		}
	}
	if (currPos == H*W)
		return 1;
	for(int shapeIndex=0; shapeIndex<4; shapeIndex++) {
		if (isLShapeInsertable(y, x, shapeIndex)) {
			for (int boxIndex=0; boxIndex<3; boxIndex++) {
				board[y + LShapeY[shapeIndex][boxIndex]][x + LShapeX[shapeIndex][boxIndex]] = 1;
			}
			count+=counter(currPos);	
			for (int boxIndex=0; boxIndex<3; boxIndex++) {
				board[y + LShapeY[shapeIndex][boxIndex]][x + LShapeX[shapeIndex][boxIndex]] = 0;
			}
		}
	}
	return count;
}
int main(){
	int C;
	int sols[30];
	char boardRaw[20][20];
	cin >> C;
	for(int i=0; i<C; i++) {
		cin >> H >> W;
		for (int j=0; j<H; j++) {
			cin >> boardRaw[j];
		}
		for (int y=0; y<H; y++) {
			for (int x=0; x<W; x++) {
				if (boardRaw[y][x] == '#')
					board[y][x] = 1;
				else
					board[y][x] = 0;
			}
		}
		sols[i] = counter(0);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
