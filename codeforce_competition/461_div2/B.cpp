#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main() {
	int cnt = 0, n, c;
	cin >> n;
	bool same[2501][2501];
	int lines[3];
	memset(same, 0, sizeof(same));
	for (int a=1; a<=n; a++) {
		for (int b=a; b<=n; b++) {
			c = a^b;
			if (n<c) continue;
			if ( a+b <= c || a+c<=b || b+c<=a ) continue;
			lines[0] = a;
			lines[1] = b;
			lines[2] = c;
			sort(lines, lines+3);
			if (same[lines[0]][lines[1]]) continue;
			same[lines[0]][lines[1]] = true;
			cnt++;
		}
	}
	cout << cnt <<endl;
}
