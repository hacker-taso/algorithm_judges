#include<iostream>
#include<algorithm>
using namespace std;

int fences[20000];
int findBiggest(int, int);

int main(void) {
	int C, N;
	int sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> N;
		for (int j=0; j<N; j++) {
			cin >> fences[j];
		}
		sols[i] = findBiggest(0, N-1);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

int findBiggest(int l, int r) {
	if (l==r)
		return fences[l];
	int mid = (l+r) / 2;
	int biggest = findBiggest(l, mid);
	biggest = max(biggest, findBiggest(mid+1, r));

	int acrossL = mid;
	int acrossR = mid;
	int minH = fences[mid];
	int currWidth = 1;
	int subBiggest = minH * currWidth;
	while (l <= acrossL && acrossR <= r) {
		if (l <= acrossL-1 && acrossR+1 <= r) {
			if (fences[acrossR+1] <= fences[acrossL-1]) { // left is bigger
				minH = min(minH, fences[acrossL-1]);
				acrossL -= 1;
			} else { // right is bigger
				minH = min(minH, fences[acrossR+1]);
				acrossR += 1;
			}
		} else if (l <= acrossL-1) { // only left
			minH = min(minH, fences[acrossL-1]);
			acrossL -= 1;
		} else if (acrossR+1 <= r) { // only right
			minH = min(minH, fences[acrossR+1]);
			acrossR += 1;
		} else
			break;
		currWidth = acrossR - acrossL + 1;
		subBiggest = max(subBiggest, minH * currWidth);
	}
	return max(biggest, subBiggest);
}
