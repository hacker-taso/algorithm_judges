#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

unsigned long long cache[100];

void cache_init() {
	// n-1 -> n자리수 만드는데 드는 비용
	// = n-2 -> n-1자리수 만드는데 드는 비용 - n-1 + n
	// = sum(tmp[i] for i=2 to n-1) - n-1 + n
	unsigned long long tmp[100];
	tmp[1] = 1;
	tmp[2] = 2;
	for (int n=3; n<=62; n++) {
		tmp[n] = 0;
		for (int i=1; i<n; i++) {
			tmp[n] += tmp[i];
		}
		tmp[n] -= n-1;
		tmp[n] += n;
	}
	// 0 -> n자리수 만드는데 드는 비용
	for (int n=1; n<=62; n++) {
		cache[n] = 0;
		for (int i=1; i<=n; i++)
			cache[n] += tmp[i];
	}
}

unsigned long long solve(unsigned long long n) {
	unsigned long long ret = 0;
	while (0 != n) {
		int pos = __builtin_ctzll(n) + 1; //__builtin_ctzll: 최하위 0 갯수
		ret += cache[pos];
		n &= (n - 1); // 최하위 1 삭제
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cache_init();
	int t;
	unsigned long long n;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		cout << solve(n) << endl;
	}
}
