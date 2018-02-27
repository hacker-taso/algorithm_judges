#include<iostream>
#include<iomanip>
using namespace std;

void initBeforeInput();
void initAfterInput();
void fillCache(int);
int map[50][50];
int numNeighbor[50];
int numCity, numDay, prisonCity;
double cache[50][101];

int main() {
	int C, testCity;
	int numTestCity[50];
	double sols[50][50];
	cin >> C;
	for (int i=0; i<C; i++) {
		initBeforeInput();
		cin >> numCity >> numDay >> prisonCity;
		for (int j=0; j<numCity; j++) {
			for (int k=0; k<numCity; k++) {
				cin >> map[j][k];
			}
		}
		initAfterInput();
		cache[prisonCity][0] = 1.0;
		for (int j=1; j<=numDay; j++) {
			fillCache(j);
		}
		cin >> numTestCity[i];
		for (int j=0; j<numTestCity[i]; j++) {
			cin >> testCity;
			sols[i][j] = cache[testCity][numDay];
		}
	}
	for (int i=0; i<C; i++) {
		for (int j=0; j<numTestCity[i]; j++) {
			cout << fixed << setprecision(8) << sols[i][j] << " ";
		}
		cout << endl;
	}
}

void fillCache(int day) {
	for (int city=0; city<numCity; city++) {
		cache[city][day] = 0.0;
		for (int neighbor=0; neighbor<numCity; neighbor++) {
			if (map[city][neighbor])
				cache[city][day] += cache[neighbor][day-1]/numNeighbor[neighbor];
		}
	}
}

void initBeforeInput() {
	for (int i=0; i<50; i++) {
		for (int j=0; j<=100; j++) {
			cache[i][j] = 0.0;
		}
	}
}
void initAfterInput() {
	for (int i=0; i<numCity; i++) {
		numNeighbor[i] = 0;
		for (int j=0; j<numCity; j++) {
			if (map[i][j])
				numNeighbor[i]++;
		}
	}
}
