#include<iostream>
#include<cstring>
#include<vector>
#define DIVISOR 10000000
using namespace std;

void init();
int countPoly(int, int);
int cache[101][101];

int main() {
	int C, numSquares;
	vector<int> sols;
	cin >> C;
	sols.resize(C, 0);
	for (int i=0; i<C; i++) {
		init();
		cin >> numSquares;
		for (int firstUsed=1; firstUsed<=numSquares; firstUsed++){
			sols[i] = (sols[i] + countPoly(firstUsed, numSquares-firstUsed)) % DIVISOR;
		}
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

void init() {
	memset(cache, -1, sizeof(cache));
}

int countPoly(int before, int remainCnt) {
	int& ret = cache[before][remainCnt];
	if (ret != -1) return ret;
	
	if (remainCnt == 0) {
		ret = 1;
		return ret;
	}

	int cnt = 0;
	for (int curUsed=1; curUsed<=remainCnt; curUsed++) {
		cnt = (cnt + ((before + curUsed - 1) * countPoly(curUsed, remainCnt-curUsed)) % DIVISOR) % DIVISOR;
	}
	ret = cnt;
	return ret;
}
