#include<iostream>
#include<cstring>
using namespace std;

int numRow, numCol;
char board[50][50];
bool checked[50][50];
bool usedRow[50];
bool usedCol[50];

bool useRow(int);

bool useCol(int hereX) {
	for (int y=0; y<numRow; y++) {
		if (board[y][hereX] == '#' && !usedRow[y]) {
			usedRow[y] = true;
			checked[y][hereX] = true;
			if (!useRow(y)) return false;
		} else if (board[y][hereX] == '.' && usedRow[y]) return false;
	}
	return true;
}

bool useRow(int hereY) {
	for (int x=0; x<numCol; x++) {
		if (board[hereY][x] == '#' && !usedCol[x]) {
			usedCol[x] = true;
			checked[hereY][x] = true;
			if (!useCol(x)) return false;
		}
	}
	return true;
}

int main() {
	memset(checked, 0, sizeof(checked));
	cin >> numRow >> numCol;
	string s;
	for (int i=0; i<numRow; i++) {
		cin >> s;
		for (int j=0; j<numCol; j++)
			board[i][j] = s[j];
	}
	for (int y=0; y<numRow; y++) {
		for (int x=0; x<numCol; x++) {
			if (board[y][x] == '#' && !checked[y][x]) {
				memset(usedCol, 0, sizeof(usedCol));
				memset(usedRow, 0, sizeof(usedRow));
				usedCol[x] = true;
				if (!useCol(x)) {
					cout << "No" << endl;
					return 0;
				}
				usedRow[y] = true;
				if (!useRow(y)) {
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
}
