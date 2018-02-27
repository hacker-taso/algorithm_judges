// Start at Feb 20, 2018
// End at Feb 20, 2018
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

int sizePowerMap[2000001];

int customPower(int n, int p) {
	if (p == 0) return 1;
	if (p == 1) return n;
	int halfRes = customPower(n, p/2);
	int res = ((long long)halfRes*halfRes)%MOD;
	if (p%2 == 1)
		res = ((long long)res*n) % MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int len, size;
	cin >> len >> size;
	vector<int> s1(len), s2(len);
	int numZero = 0;
	for (int i=0; i<len; i++) {
		cin >> s1[i];
		if (s1[i] == 0) numZero++;
	}
	for (int i=0; i<len; i++) {
		cin >> s2[i];
		if (s2[i] == 0) numZero++;
	}
	sizePowerMap[0] = 1;
	for (int i=1; i<=len*2; i++) {
		sizePowerMap[i] = (long long)sizePowerMap[i-1]*size % MOD;
	}
	int P = 0;
	int Q = sizePowerMap[numZero];
	bool found = false;
	int curNumZero = 0;
	int numSameZero = 0;
	for (int i=0; i<len; i++) {
		if (s1[i] == 0 && s2[i] == 0) {
			found = true;
			int multiplier = sizePowerMap[numSameZero];
			multiplier = (long long)multiplier*(size-1) %MOD;
			multiplier = (long long)multiplier*size/2 % MOD;
			P = (P + (long long)sizePowerMap[numZero-curNumZero-2]*multiplier) % MOD;
			numSameZero++;
			curNumZero+=2;
		} else if (s1[i] == 0) {
			found = true;
			int multiplier = sizePowerMap[numSameZero];
			multiplier = (long long)multiplier*(size-s2[i]) %MOD;
			P = (P + (long long)sizePowerMap[numZero-curNumZero-1]*multiplier) % MOD;
			curNumZero++;
		} else if (s2[i] == 0) {
			int multiplier = sizePowerMap[numSameZero];
			multiplier = (long long)multiplier*(s1[i]-1) % MOD;
			found = true;
			P = (P + (long long)sizePowerMap[numZero-curNumZero-1]*multiplier) % MOD;
			curNumZero++;
		} else if (s1[i] < s2[i] && !found) {
			P = 0; Q = 1; break;
		} else if (s2[i] < s1[i] && !found) {
			P = 1; Q = 1; break;
		} else if (s2[i] < s1[i] && found) {
			int multiplier = sizePowerMap[numSameZero];
			P = (P + (long long)sizePowerMap[numZero-curNumZero]*multiplier) % MOD;
			break;
		} else if (s1[i] < s2[i] && found) {
			break;
		}
	}
	for (int i=2; i<=size; i++) {
		while (P%i==0 && Q%i==0) {
			P/=i;
			Q/=i;
		}
	}
	int QInv = customPower(Q, MOD-2);
	int R = (long long)P*QInv % MOD;
	cout << R << endl;
}
