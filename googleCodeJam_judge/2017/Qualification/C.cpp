// Start at 09:00PM March 03, 2018
// End at 09:49PM March 03, 2018
// Retrospection
// Mistake#1. I used long type instead of long long type.
// Mistake#2. (Important) I didn't initialize "spaces" map. This is the mistake which cost me considerable amount of time.
#include<iostream>
#include<map>
using namespace std;

long long N;
long long K;
map<long long, long long> spaces;

int main() {
	int C;
	long long size, frequency;
	long long maxVal, minVal;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> N >> K;
		spaces = map<long long, long long>();
		spaces[N] = 1;
		while (K) {
			tie(size, frequency) = *spaces.rbegin();
			spaces.erase(spaces.rbegin()->first);
			minVal = (size-1)/2;
			maxVal = size/2;
			if (K<=frequency)
				break;
			spaces[minVal] += frequency;
			spaces[maxVal] += frequency;
			K-=frequency;
		}
		cout << "Case #" << i+1 << ": " << maxVal << " " << minVal<< endl;
	}
}
