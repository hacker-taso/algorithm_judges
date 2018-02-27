#include<iostream>
#include<cstring>
#include<algorithm>
#define DENOM 1000000007
using namespace std;

int eArr[14], sortedEArr[14];
int numLen;
int m;
// prev mod, map
int cache[20][1<<14][2];

void init() {
	memset(cache, -1, sizeof(cache));
}

void postInputInit(long long e) {
	for (int i=0; i<14; i++) {
		eArr[i] = e%10;
		sortedEArr[i] = eArr[i];
		e = e/10;
		if (e==0) {
			numLen = i+1;
			break;
		}
	}
	sort(sortedEArr, sortedEArr + numLen);
}

// r: remain
int count(int r, int map, int pos, bool isSmall) {
	if (pos == -1) {
		if (r == 0 && isSmall == true)
			return 1;
		else
			return 0;
	}
	int &ret = cache[r][map][isSmall];
	if (ret != -1) return ret;

	int originNum = eArr[pos];
	int sum = 0;
	for (int sel=0; sel<numLen; sel++) {
		if (((map >> sel) & 1) == 0) {
			if (!isSmall && originNum < sortedEArr[sel])
				continue;
			if (0<sel && sortedEArr[sel] == sortedEArr[sel-1] && (map & (1<<(sel-1))) == 0) {
				continue;
			}
			sum = ( sum + count((r*10 + sortedEArr[sel]) % m, map | (1 << sel), pos-1, isSmall || (sortedEArr[sel] < originNum)) )%DENOM;
		}
	}
	ret = sum;
	return ret;
}

int main() {
	int C;
	int sols[50];
	cin >> C;
	long long e;
	for (int i=0; i<C; i++) {
		init();
		cin >> e >> m;
		postInputInit(e);
		// -1: same number excluding
		sols[i] = count(0, 0, numLen-1, false);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
