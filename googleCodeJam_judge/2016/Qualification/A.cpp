// Start at 08:06PM March 25, 2018
// End at 08:28PM March 25, 2018
// Retrospection:
// Actually, except "0", we can make 1.
// For example, ----9 can be ---81 with multiplier 9. Also, -----2 can be ----10 and so on.
// So, we can find a solution in constant time.
// (To be honest, I thought complicatedly and I thought we should run 10^6 times in worst case.)
#include<iostream>
using namespace std;

long long solve(long long N) {
	bool checked[10] = {0};
	for (int i=1; i<=1000000; i++) {
		long long mul = N*i;
		while (mul) {
			checked[mul%10] = 1;
			mul/=10;
		}
		bool allChecked = true;
		for (int j=0; j<10; j++)
			if (!checked[j]) {
				allChecked = false;
				break;
			}
		if (allChecked) return N*i;
	}
	return -1;
}

int main() {
	int T, N;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		long long sol = solve(N);
		cout << "Case #" << i+1 << ": ";
		if (sol < 0)
			cout << "INSOMNIA" <<endl;
		else
			cout << sol << endl;
	}
}
