// Retrospection: I got wrong answer because of (int)pow(10,2)=> 99
// I got accepted with (int)(pow(10,2)+0.5) in practice.
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

//totalLen, curVal
int cache[20][11];
void init() {
	memset(cache, -1, sizeof(cache));
}

int getCount(int totalLen, int remainVal) {
	int& ret = cache[totalLen][remainVal];
	if (ret != -1) return ret;
	if (totalLen == 1) {
		if (remainVal <= 9)
			ret = 1;
		else
			ret = 0;
		return ret;
	}
	int cnt=0;
	for (int i=0; i<=remainVal; i++) {
		cnt+=getCount(totalLen-1, i);
	}
	ret = cnt;
	return ret;
}

int getFirstCount(int totalLen, int remainVal) {
	int cnt = 0; 
	for (int i=1; i<10; i++) {
		if (remainVal-i < 0) continue;
		cnt+=getCount(totalLen-1, remainVal-i);
	}
	return cnt;
}

int main() {
	int k;
	cin >> k;
	init();
	int cnt = 0;
	int sol = 0;

	int numDigit;
	int remainVal;
	int m;
	string tmp;
	for (int i=2; i<20; i++) {
		if (k<=cnt+getFirstCount(i, 10)) {
			numDigit = i;
			remainVal = 10;
			m = 1;
			for (int j=0; j<numDigit-1; j++) {
				for (;m<=remainVal; m++) {
					if (k<=cnt+getCount(i-j-1,remainVal-m)) {
						sol += m*(int)(pow(10, numDigit-1-j)+0.5);

						remainVal -= m;
						break;
					} else {
						cnt += getCount(i-j-1, remainVal-m);
					}
				}
				m = 0;
			}
			sol+=remainVal;
			cout << sol << endl;
			return 0;
		} else {
			cnt+=getFirstCount(i, 10);
		}
	}
}
