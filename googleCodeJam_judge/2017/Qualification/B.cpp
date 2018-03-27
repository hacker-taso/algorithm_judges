// Start at 07:16PM March 03, 2018
// End at 07:57PM March 03, 2018
// fail in the large set
// Retrospection:
// 1. Mistake#1 I didn't think the case 1112220. This should output 1111999 but my out put was 999999
// 2. Mistake#2 when counting the number of digits, the program counted one digit more.
#include<iostream>
using namespace std;

long long N;

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> N;
		long long maxPosNum = 1;
		long long tmp = N;
		tmp/=10;
		while (tmp) {
			maxPosNum *= 10;
			tmp/=10;
		}
		long long pos;
		int curVal = (N/maxPosNum) % 10;
		long long untilIncreasing = curVal * maxPosNum;
		long long segment = 0;
		for (pos=maxPosNum/10; 0<pos; pos/=10) {
			int prevVal = curVal;
			curVal = (N/pos) % 10;
			segment += curVal * pos;
			if (curVal < prevVal)
				break;
			if (prevVal < curVal) {
				untilIncreasing += segment;
				segment = 0;
			}
		}
		tmp = segment;
		while (tmp) {
			maxPosNum *= 10;
			tmp/=10;
		}
		untilIncreasing += (segment/maxPosNum)*maxPosNum;
		if (pos == 0) // already non-decreasing
			cout << "Case #" << i+1 << ": " << N << endl;
		else {
			cout << "Case #" << i+1 << ": " << untilIncreasing-1 << endl;
		}
	}
}
