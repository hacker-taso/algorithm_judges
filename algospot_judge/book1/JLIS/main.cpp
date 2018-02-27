#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define MINUS_INF -0x123456789

void init();
int findJLIS(int, int);
int aLen, bLen;
int A[100], B[100];
int cache[101][101];

int main() {
	int C;
	int sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> aLen >> bLen;
		for (int j=0; j<aLen; j++) {
			cin >> A[j];
		}
		for (int j=0; j<bLen; j++) {
			cin >> B[j];
		}
		sols[i] = findJLIS(-1, -1);
	}

	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

void init() {
	memset(cache, -1, sizeof(cache));
}

int findJLIS(int aStart, int bStart) {
	int& ret = cache[aStart+1][bStart+1];
	if (ret != -1)
		return ret;
	long long curVal;
	if (aStart == -1 && bStart == -1)
		curVal = MINUS_INF;
	else if (aStart == -1) {
		curVal = B[bStart];
	} else if (bStart == -1) {
		curVal = A[aStart];
	} else {
		curVal = max(A[aStart], B[bStart]);
	}
	int retTmp = 0;
	for (int i=aStart+1; i<aLen; i++) {
		if (curVal < A[i])
			retTmp = max(retTmp, 1+findJLIS(i, bStart));
	}
	for (int i=bStart+1; i<bLen; i++) {
		if (curVal < B[i])
			retTmp = max(retTmp, 1+findJLIS(aStart, i));
	}
	ret = retTmp;
	return ret;
}
