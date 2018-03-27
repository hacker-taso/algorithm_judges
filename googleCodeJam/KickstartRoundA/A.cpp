#include<iostream>
using namespace std;
long long N;

bool check(long long x) {
	while (x) {
		if (x%2!=0) return false;
		x/=10;
	}
	return true;
}

long long solve() {
	long long maxPosNum = 1;
	long long tmp = N;
	tmp/=10;
	while (tmp) {
		maxPosNum *= 10;
		tmp/=10;
	}
	long long positive = maxPosNum*2;
	long long negative = 0;
	for (long long cand = 8; cand<maxPosNum; cand = cand*10+8) {
		negative = cand;
	}
	long long itN = N;
	long long curVal = 0;
	while (maxPosNum) {
		int digit = itN/maxPosNum;
		if (digit%2 == 1) {
			if (maxPosNum == 1) return 1;
			else {
				long long positive;
				if (digit == 9 && !check(curVal+maxPosNum*10))
					positive = 2*maxPosNum*(digit+1);
				else
					positive =  maxPosNum*(digit+1);
				negative = maxPosNum*(digit-1) + negative;
				return min(itN - negative, positive-itN);
			}
		}
		curVal += maxPosNum*digit;
		itN -= maxPosNum*digit;
		maxPosNum /= 10;
		negative /= 10;
	}
	return 0;
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}
}
