#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int cache[100][100];
int board[100][100];
int size;

void init() {
	memset(cache, -1, sizeof(cache));
}

bool solve(int y, int x) {
	if (y<0 || size<=y || x<0 || size<=x)
		return 0;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	if (y == size-1 && x == size-1) {
		ret = 1;
		return ret;
	}
	int num = board[y][x];
	if (solve(y+num, x) || solve(y, x+num)) {
		ret = 1;
		return ret;
	}
	ret = 0;
	return ret;
}

int main() {
	int C;
	vector<bool> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> size;
		for (int j=0; j<size; j++) {
			for (int k=0; k<size; k++) {
				cin >> board[j][k];
			}
		}
		sols.push_back(solve(0, 0));
	}
	for (int i=0; i<C; i++) {
		cout << (sols[i] ? "YES" : "NO") <<endl;
	}
}
