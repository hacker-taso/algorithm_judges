#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

int N, K;
vector<int> values;

double calcPow(double n, int k) {
	double logN = log(n);
	double p = 0;
	for (int i=0; i<k; i++)
		p += logN;
	return exp(p);
}

double getE(int k) {
	if (k==1 || k==0) {
		double oneTryE = 0;
		double sum = 0;
		for (int i=0; i<N; i++)
			sum += values[i];
		oneTryE = sum / N;
		if (k==0)
			return oneTryE;
		double goodValV = 0, badValV = 0;
		int badValN = 0;
		for (int i=0; i<N; i++) {
			if (oneTryE<=values[i]) {
				goodValV += values[i];
			}
			else {
				badValN += 1;
				badValV += values[i];
			}
		}
		goodValV /= N;
		badValV /= N;
		return goodValV * (1-calcPow((double)badValN/N, k+1)) / (1-(double)badValN/N) + calcPow((double)badValN/N, k)*badValV;
	} else {
		double nextE = getE(k-1);
		double goodValV = 0, badValV = 0;
		int badValN = 0;
		for (int i=0; i<N; i++) {
			if (nextE<=values[i]) {
				goodValV += values[i];
			}
			else {
				badValN += 1;
			}
		}
		goodValV /= N;
		return goodValV + (double)badValN/N * nextE;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N >> K;
		values = vector<int>(N);
		for (int j=0; j<N; j++) {
			cin >> values[j];
		}
		cout << "Case #" << i+1 << ": " << fixed << setprecision(9) << getE(K) << endl;
	}
}
