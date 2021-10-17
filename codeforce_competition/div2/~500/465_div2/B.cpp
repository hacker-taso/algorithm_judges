// Start at 1:40AM Feb 20, 2018
// End at 1:48AM Feb 20, 2018
#include<iostream>
#define DOWN 0
#define UP 1
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int posX = 0, posY = 0, pos;
	if (s[0] == 'U') {
		posY++;
		pos = UP;
	} else {
		posX++;
		pos = DOWN;
	}
	int cnt = 0;
	for (int i=1; i<n; i++) {
		if (s[i] == 'U')
			posY++;
		else
			posX++;
		if (pos == UP && posY < posX) {
			cnt++;
			pos = DOWN;
		} else if (pos == DOWN && posX < posY) {
			cnt++;
			pos = UP;
		}
	}
	cout << cnt << endl;
}
