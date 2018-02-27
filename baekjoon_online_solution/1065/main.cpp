#include<iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	if (N < 100) {
		cout << N;
	} else {
		int cnt = 0;
		int tens;
		int units;
		int hundreds;
		for (int i=100; i<=N; i++) {
			hundreds = i/100;
			tens = (i/10)%10;
			units = i%10;
			if (hundreds - tens == tens - units)
				cnt++;
		}
		cout << 99 + cnt << endl;
	}
}

