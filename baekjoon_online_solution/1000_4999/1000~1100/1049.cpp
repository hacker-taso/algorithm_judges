#include<iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int**B = new int*[M];
	enum Index{P6=0,U=1};
	for (int i=0; i<M; i++) {
		B[i] = new int[2];
		cin >> B[i][P6] >> B[i][U];
	}

	int min[7]={0, 6000, 6000, 6000, 6000, 6000, 6000};
	for (int i=0; i<M; i++) {
		for (int j=1; j<7; j++) {
			if (B[i][P6] < min[j])
				min[j] = B[i][P6];
			if (B[i][U]*j < min[j])
				min[j] = B[i][U]*j;
		}
	}
	int minAll = min[6]*(N/6) + min[N%6];
	cout << minAll << endl;
}

