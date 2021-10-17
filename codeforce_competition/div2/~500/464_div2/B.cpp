// Start at 07:09PM Feb 17, 2018
// End at 07:18PM Feb 17, 2018
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	long long N;
	int K;
	cin >> N >> K;
	vector<long long> capacities(K, 0);
	for (int i=0; i<K; i++)
		cin >> capacities[i];
	int idx = -1;
	long long minRemain = 0x7654321076543210ul;
	for (int i=0; i<K; i++) {
		if ((N%capacities[i]) < minRemain) {
			idx = i;
			minRemain = N%capacities[i];
		}
	}
	long long numBox =N/capacities[idx];
	cout << (idx+1) << " " <<numBox <<endl;
}
