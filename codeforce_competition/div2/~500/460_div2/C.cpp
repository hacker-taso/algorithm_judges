#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int seats[2000][2000];

int main() {
	int numRows, numCols, k;
	string tmp;
	cin >> numRows >> numCols >> k;
	for (int i=0; i<numRows; i++) {
		cin >> tmp;
		for (int j=0; j<numCols; j++)
			seats[i][j] = tmp[j] == '.';
	}
	int sol = 0;
	if (k==1) {
		for (int i=0;i<numRows; i++) {
			for (int j=0; j<numCols; j++) {
				sol+=seats[i][j];
			}
		}
		cout << sol <<endl;
		return 0;
	}
	int partialSum[2001];
	// x dir check
	for (int y=0; y<numRows; y++) {
		partialSum[0] = 0;
		for (int x=0; x<numCols; x++) {
			partialSum[x+1] = partialSum[x] + seats[y][x];
		}
		for (int x=0; x+k<=numCols; x++) {
			if (partialSum[x+k]-partialSum[x] == k) {
				sol++;
			}
		}
	}
	// y dir check
	for (int x=0; x<numCols; x++) {
		partialSum[0] = 0;
		for (int y=0; y<numRows; y++) {
			partialSum[y+1] = partialSum[y] + seats[y][x];
		}
		for (int y=0; y+k<=numRows; y++) {
			if (partialSum[y+k]-partialSum[y] == k) {
				sol++;
			}
		}
	}
	cout << sol <<endl;
}
