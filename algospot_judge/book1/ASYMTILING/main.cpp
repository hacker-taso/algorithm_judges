#include<iostream>
#include<cstring>
#define DIVIDER 1000000007
using namespace std;

void init();
int getAll(int);
int getSym(int);
int cacheAll[101];
int cacheSym[101];

int main() {
	int C;
	int sols[50];
	int width;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> width;
		sols[i] = (DIVIDER + getAll(width) - getSym(width))%DIVIDER;
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

void init() {
	memset(cacheAll, -1, sizeof(cacheAll));
	memset(cacheSym, -1, sizeof(cacheSym));
}

int getAll(int n) {
	int& ret = cacheAll[n];
	if (ret != -1) return ret;
	if (n == 1)
		ret = 1;
	else if (n == 2)
		ret = 2;
	else {
		ret = (getAll(n-1) + getAll(n-2))%DIVIDER;
	}
	return ret;
}

int getSym(int n) {
	int & ret = cacheSym[n];
	if (ret != -1) return ret;
	if (n == 0) { // I think I should fix this code because it's not intuitive
		ret = 1;
	} else if (n == 1) {
		ret = 1;
	} else if (n == 2) {
		ret = 2;
	} else if (n == 3) {
		ret = 1;
	} else {
		ret = (getSym(n-2) + getSym(n-4))%DIVIDER;
	}
	return ret;
}
