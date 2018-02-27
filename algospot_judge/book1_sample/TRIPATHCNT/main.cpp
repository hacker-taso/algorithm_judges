#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int sumCache[100][100];
int cntCache[100][100];
int board[100][100];
int size;

void init() {
	memset(sumCache, -1, sizeof(sumCache));
	memset(cntCache, -1, sizeof(cntCache));
}

int findMaxSum(int y, int x) {
	if (y<0 || size<=y || x<0 || size<=x)
		return 0;
	int& ret = sumCache[y][x];
	if (ret != -1) return ret;
	int curNum = board[y][x];
	ret = curNum + max(findMaxSum(y+1, x), findMaxSum(y+1, x+1));
	return ret;
}

int countMaxSum(int y, int x) {
	if (y<0 || size<=y || x<0 || size<=x)
		return 0;
	if (y == size-1)
		return 1;
	int& ret = cntCache[y][x];
	if (ret != -1) return ret;
	int curNum = board[y][x];
	int curSum = sumCache[y][x];
	int nextSum = curSum-curNum;
	int cnt = 0;
	if (y+1<size && sumCache[y+1][x] == nextSum)
		cnt += countMaxSum(y+1, x);
	if (y+1<size && x+1<size && sumCache[y+1][x+1] == nextSum)
		cnt += countMaxSum(y+1, x+1);
	ret = cnt;
	return ret;
}

int solve() {
	findMaxSum(0, 0);
	return countMaxSum(0, 0);
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> size;
		for (int j=0; j<size; j++) {
			for (int k=0; k<=j; k++) {
				cin >> board[j][k];
			}
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
