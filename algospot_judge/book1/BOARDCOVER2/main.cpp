// Retrospection: 
// mistake: type of function is int solve(~) but there was no return value.
// New things learned: 1. to check conflict between board and block, using vector rather than 2d array.
// 2. TryFill(1) and TryFill(-1)
#include<iostream>
#include<vector>
#include<cassert>
using namespace std;
#define Y 0
#define X 1

void fillLShapeR(); // function check complete
bool tryFill(int y, int x, int lType, int fillNum);
void solve(int curPosY, int curPosX, int curScore);
//void search(int);

int bW, bH;
char board[10][10];
int lW, lH;
char lShape[10][10];
int lShpaeBlockCnt;
// lShapeR
int lShapeRLen;
char lShapeR[4][10][10];
vector<char> lShapeRX[4];
vector<char> lShapeRY[4];
int lShapeRW[4];
int lShapeRH[4];
int lShapeRNW[4][2];

int maxSolution = 0;

int evaluate(int curPosY, int curPosX) {
	int zeroCnt = 0;
	int j=curPosX;
	for (int i=curPosY; i<bH; i++) {
		for (;j<bW; j++) {
			if (!board[i][j])
				zeroCnt++;
		}
		j=0;
	}
	return zeroCnt/lShpaeBlockCnt;
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	sols.resize(C, 0);
	string inTmp;
	for (int i=0; i<C; i++) {
		cin >> bH >> bW >> lH >> lW;
		// board input
		for (int j=0; j<bH; j++) {
			cin >> inTmp;
			for (int k=0; k<bW; k++) {
				board[j][k] = (inTmp[k] == '.') ? 0 : 1;
			}
		}
		// lShape input
		for (int j=0; j<lH; j++) {
			cin >> inTmp;
			for (int k=0; k<lW; k++) {
				lShape[j][k] = (inTmp[k] == '.') ? 0 : 1;
			}
		}
		fillLShapeR();
		maxSolution = 0;
		solve(0, 0, 0);
		sols[i] = maxSolution;
	}
	//epilogue
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

bool tryFill(const int y, const int x, const int lType, const int fillNum) {
	bool canFill = true;
	const int RNWY = lShapeRNW[lType][Y];
	const int RNWX = lShapeRNW[lType][X];
	const int RH = lShapeRH[lType];
	const int RW = lShapeRW[lType];
	if ( bW-1 < x + (RW-RNWX) - 1 || bH-1 < y + (RH-RNWY) - 1
		|| x - RNWX < 0 || y-RNWY < 0)
		return false;
	int len = lShapeRX[lType].size();
	vector <char>& lShapeX = lShapeRX[lType];
	vector <char>& lShapeY = lShapeRY[lType]; // retrospection 1.
	for (int i=0; i<len; i++) {
		if (board[y+lShapeY[i]][x+lShapeX[i]])
			canFill = false;
		board[y+lShapeY[i]][x+lShapeX[i]] += fillNum;
	}
	return canFill;
}

void solve(int curPosY, int curPosX, int curScore) {
	if (curScore+evaluate(curPosY, curPosX) < maxSolution)
		return;
	int tmp;
	for (; curPosY<bH; curPosY++) {
		for (; curPosX<bW; curPosX++) {
			if (!board[curPosY][curPosX]) {
				for (int lType=0; lType<lShapeRLen; lType++) {
					if (tryFill(curPosY, curPosX, lType, 1)) {
						solve(curPosY+(curPosX+1)/bW, (curPosX+1)%bW, curScore+1);
					}
					tryFill(curPosY, curPosX, lType, -1);
				}
			}
		}
		curPosX = 0;
	}
	maxSolution = max(curScore, maxSolution);
}
/*
void search(int placed) {
	if (placed+evaluate(0, 0) < maxSolution)
		return;
	int y=-1, x=-1;
	for (int i=0; i<bH; i++) {
		for (int j=0; j<bW; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y!=-1) break;
	}
	if (y==-1) {
		maxSolution = max(maxSolution, placed);
		return;
	}

	for (int i=0; i<lShapeRLen; i++) {
		if (tryFill(y, x, i, 1))
			search(placed+1);
		tryFill(y, x, i, -1);
	}
	board[y][x] = 1;
	search(placed);
	board[y][x] = 0;
}*/

void fillLShapeR() {
	lShpaeBlockCnt = 0;
	// fill LshapeR
	for (int i=0; i<lH; i++) {
		for (int j=0; j<lW; j++) {
			lShapeR[0][i][j] = lShape[i][j];
			if (lShape[i][j] == 1)
				lShpaeBlockCnt++;
		}
	}
	lShapeRW[0] = lW;
	lShapeRH[0] = lH;
	for (int i=0; i<3; i++) {
		for (int j=0; j<lShapeRH[i]; j++) {
			for (int k=0; k<lShapeRW[i]; k++) {
				lShapeR[i+1][k][lShapeRH[i]-1-j] = lShapeR[i][j][k];
			}
		}
		lShapeRH[i+1] = lShapeRW[i];
		lShapeRW[i+1] = lShapeRH[i];
	}
	// decide lShapeRLen
	bool oneRSame = true;
	bool twoRSame = true;
	// oneRSame
	if (lShapeRH[0] == lShapeRH[1] && lShapeRW[0] == lShapeRW[1]) {
		for (int i=0; i<lShapeRH[0]; i++) {
			for (int j=0; j<lShapeRW[0]; j++) {
				if (lShapeR[0][i][j] != lShapeR[1][i][j]) {
					oneRSame = false;
					break;
				}
			}
		}
	} else
		oneRSame = false;
	// twoRSame
	for (int i=0; i<lShapeRH[0]; i++) {
		for (int j=0; j<lShapeRW[0]; j++) {
			if (lShapeR[0][i][j] != lShapeR[2][i][j]) {
				twoRSame = false;
				break;
			}
		}
	}
	if (oneRSame)
		lShapeRLen = 1;
	else if (twoRSame)
		lShapeRLen = 2;
	else
		lShapeRLen = 4;
	// lShapeRNW
	for (int i=0; i<lShapeRLen; i++) {
		for (int j=0; j<lShapeRH[i]; j++) {
			bool found = false;
			for (int k=0; k<lShapeRW[i]; k++) {
				if (lShapeR[i][j][k] == 1) {
					found = true;
					lShapeRNW[i][Y] = j;
					lShapeRNW[i][X] = k;
					break;
				}
			}
			if (found)
				break;
		}
	}
	for (int i=0; i<lShapeRLen; i++) {
		lShapeRX[i].clear();
		lShapeRY[i].clear();
		for (int j=0; j<lShapeRH[i]; j++) {
			for (int k=0; k<lShapeRW[i]; k++) {
				if (lShapeR[i][j][k]) {
					lShapeRY[i].push_back(j-lShapeRNW[i][Y]);
					lShapeRX[i].push_back(k-lShapeRNW[i][X]);
				}
			}
		}
	}
}
