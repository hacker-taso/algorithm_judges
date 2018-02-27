// Retrospection long after writing this code: 
// Making posToHint and querying info with hint number is very good way.
#include<iostream>
#include<cstring>
#define BLACK 0
#define WHITE 1
#define HORIZON 0
#define VERTICAL 1
using namespace std;

//boardInfo
int boardSize, hintCnt;
int COLOR[20][20], BOARD[20][20];
int posToHint[20][20][2];
// hint info
int SUM[400], LEN[400], KNOWN[400];

// sum, len, known
int candidates[46][10][1024];

int getSum(int set) {
	int sum = 0;
	for (int i=1; i<=9; i++) {
		if (set & (1<<i))
			sum += i;
	}
	return sum;
}

int getLen(int set) {
	return __builtin_popcount(set);
}

void candidatesInit() {
	int sum, known, subset, len;
	// a set is a solution in one line
	for (int set=0; set<1024; set+=2) {
		sum = getSum(set);
		len = getLen(set);
		subset = set;
		while (true) {
			// subset: known, (known | x = set) => x = set & ~known
			candidates[sum][len][subset] |= set & ~subset;
			if (subset == 0) break;
			subset = (subset-1) & set;
		}
	}
}

void put(int y, int x, int num) {
	int hintIdx;
	for (int i=0; i<2; i++) {
		hintIdx = posToHint[y][x][i];
		KNOWN[hintIdx] |= 1<<num;
	}
	BOARD[y][x] = num;
}

void remove(int y, int x) {
	int hintIdx;
	for (int i=0; i<2; i++) {
		hintIdx = posToHint[y][x][i];
		KNOWN[hintIdx] ^= 1<<BOARD[y][x];
	}
	BOARD[y][x] = 0;
}

void hintAdd(int y, int x, int direction, int sum, int hintIdx) {
	int yIt = y, xIt = x;
	int len = 0;
	if (direction == HORIZON) {
		for (xIt+=1; xIt<boardSize && COLOR[y][xIt] == WHITE; xIt++) {
			len++;
			posToHint[y][xIt][direction] = hintIdx;
		}
		LEN[hintIdx] = len;
	} else {
		for (yIt+=1; yIt<boardSize && COLOR[yIt][x] == WHITE; yIt++) {
			len++;
			posToHint[yIt][x][direction] = hintIdx;
		}
		LEN[hintIdx] = len;
	}
	SUM[hintIdx] = sum;
}

int getCandidates(int y, int x) {
	int hintIdx1 = posToHint[y][x][0];
	int hintIdx2 = posToHint[y][x][1];
	return candidates[SUM[hintIdx1]][LEN[hintIdx1]][KNOWN[hintIdx1]] &
		candidates[SUM[hintIdx2]][LEN[hintIdx2]][KNOWN[hintIdx2]];
}

bool solve() {
	int minY = -1;
	int minX = -1;
	int minCand = (1<<10) - 1;
	int curCand;
	for (int y=0; y<boardSize; y++) {
		for (int x=0; x<boardSize; x++) {
			if (COLOR[y][x] == WHITE && BOARD[y][x] == 0) {
				curCand = getCandidates(y, x);
				if (getLen(curCand) < getLen(minCand)) {
					minY = y; minX = x;
					minCand = curCand;
				}
			}
		}
	}
	if (minCand == 0) {
		return false;
	}
	if (minY == -1) {
		return true;
	}
	for (int val=1; val<=9; val++) {
		if (minCand & (1<<val)) {
			put(minY, minX, val);
			if (solve()) return true;
			remove(minY, minX);
		}
	}
	return false;
}

void init() {
	memset(BOARD, 0, sizeof(BOARD));
	memset(COLOR, 0, sizeof(COLOR));
	memset(posToHint, 0, sizeof(posToHint));
	memset(SUM, 0, sizeof(SUM));
	memset(LEN, 0, sizeof(LEN));
	memset(KNOWN, 0, sizeof(KNOWN));
}

int main() {
	candidatesInit();
	int C, y, x, direction, sum;
	string tmp;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> boardSize;
		for (int j=0; j<boardSize; j++) {
			for (int k=0; k<boardSize; k++) {
				cin >> COLOR[j][k];
			}
		}
		cin >> hintCnt;
		for (int j=0; j<hintCnt; j++) {
			cin >> y >> x >> direction >> sum;
			hintAdd(y-1, x-1, direction, sum, j);
		}
		solve();
		for (int j=0; j<boardSize; j++) {
			for (int k=0; k<boardSize; k++) {
				cout << BOARD[j][k];
				if (k+1!=boardSize)
					cout << " ";
			}
			cout << endl;
		}
	}
}
