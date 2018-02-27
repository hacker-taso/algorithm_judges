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

int solve(int y, int x) {
	if (y<x || size<=y)
		return 0;
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	int curNum = board[y][x];
	int maxChild = max(solve(y+1, x), solve(y+1, x+1));
	ret = curNum + maxChild;
	return ret;
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> size;
		for (int j=0; j<size; j++) {
			for (int k=0; k<=j; k++)
				cin >> board[j][k];
		}
		sols.push_back(solve(0, 0));
	}
	for (int i=0; i<C; i++)
		cout << sols[i] << endl;
}
