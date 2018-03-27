// I read the editorial.
// Restrospection
// 1. cakes[x][y] instead of cakes[y][x]
#include<iostream>
#include<cstring>
using namespace std;

int numRow, numCol;
bool checked[25][25];
string cakes[25];

void init() {
	memset(checked, 0, sizeof(checked));
}

void solve(int yMin, int yMax, int xMin, int xMax) {
	if (yMax<yMin || xMax<xMin)
		return;
	bool found = false;
	int foundY, foundX;
	char foundChar;
	for (int y=yMin; y<=yMax; y++) {
		for (int x=xMin; x<=xMax; x++) {
			if (cakes[y][x] != '?' && !found) {
				found = true;
				foundY = y;
				foundX = x;
				foundChar = cakes[y][x];
			} else if (cakes[y][x] != '?' && found) {
				if (foundY < y) {
					solve(yMin, foundY, xMin, xMax);
					solve(foundY+1, yMax, xMin, xMax);
				} else if (foundX < x) {
					solve(yMin, yMax, xMin, foundX);
					solve(yMin, yMax, foundX+1, xMax);
				}
				return;
			}
		}
	}
	for (int y=yMin; y<=yMax; y++) {
		for (int x=xMin; x<=xMax; x++) {
			cakes[y][x] = foundChar;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		init();
		cin >> numRow >> numCol;
		for (int j=0; j<numRow; j++)
			cin >> cakes[j];
		solve(0, numRow-1, 0, numCol-1);
		cout << "Case #" << i+1 << ":" << endl;
		for (int j=0; j<numRow; j++) {
			cout << cakes[j] << endl;
		}
	}
}
