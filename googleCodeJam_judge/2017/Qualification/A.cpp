// Start at 06:32PM March 03, 2018
// End at 06:49PM March 03, 2018
#include<iostream>
#define HAPPY '+'
#define BLANK '-'
using namespace std;

int K;
string pancakes;
bool flipFrom(int start) {
	if (pancakes.size() <= start+K-1)
		return false;
	for (int i=0; i<K; i++) {
		pancakes[start+i] = (pancakes[start+i]==HAPPY) ? BLANK : HAPPY;
	}
	return true;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> pancakes >> K;
		int j=0;
		int cnt=0;
		for (; j<pancakes.size(); j++) {
			if (pancakes[j] == BLANK) {
				if (!flipFrom(j))
					break;
				else
					cnt++;
			}
		}
		cout << "Case #" << i+1 << ": ";
		if (j != pancakes.size()) {
			cout << "IMPOSSIBLE" <<endl;
		} else {
			cout << cnt << endl;
		}
	}
}
