#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

bool board[1000][1000];
int A;

void init() {
	memset(board, 0, sizeof(board));
}

int getEmptyCnt(int y, int x) {
	int cnt = 0;
	for (int i=y-1; i<=y+1; i++) {
		for (int j=x-1; j<=x+1; j++) {
			cnt += !board[i][j];
		}
	}
	return cnt;
}

void solve() {
	int tlX = 1, tlY=1, width = (int)sqrt(A), height = A/width;
	if (height * width < A) height+=1;
	while (true) {
		int maxCnt = 0, maxX = -1, maxY = -1;
		for (int y=tlY+1; y<tlY+height; y++) {
			for (int x=tlX+1; x<tlX+width; x++) {
				int curCnt = getEmptyCnt(y, x);
				if (maxCnt<curCnt) {
					maxCnt = curCnt;
					maxY = y;
					maxX = x;
				}
			}
		}
		cout << maxY << " " << maxX << endl;
		int resY, resX;
		cin >> resY >> resX;
		if (resY == 0 && resX == 0)
			return;
		board[resY][resX] = 1;
	}
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		init();
		cin >> A;
		solve();
	}
}
