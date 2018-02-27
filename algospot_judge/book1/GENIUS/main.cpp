// retrospection: I thought prob(t-1) = prob(t-2)*lenProb(1) + prob(t-3)*lenProb(2) + prob(t-4)*lenProb(3).
// So, I made a matrix whose almost all elements are zero.
// But I should have made prob(t-1) = prob(t-1) and only prob(t) = prob(t-1)~ prob(t-2)~ ~~~ matrix.
// I think it's because I cannot calculate prob(t-5), prob(t-6) and so on to calculate prob(t-3).
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int numSongs;
int K;
int numLikes;
int songLens[50];
double nextProb[50][50];
int likeSongs[10];
double W[200][200];
double CMatrix[200][200];
double resultMatrix[200][200];
double resultTmp[200][200];

void init() {
	memset(W, 0, sizeof(W));
	memset(CMatrix, 0, sizeof(CMatrix));
	memset(resultMatrix, 0, sizeof(resultMatrix));
	memset(resultTmp, 0, sizeof(resultTmp));
}

void makeW() {
	for (int i=0; i<3*numSongs; i++) {
		W[i][i+numSongs] = 1.0;
	}
	for (int i=numSongs*3; i<numSongs*4; i++) { // y
		for (int j=0; j<numSongs*4; j++) { // x
			if (4-j/numSongs == songLens[j%numSongs]) {
				W[i][j] = nextProb[j%numSongs][i%numSongs];
			} else {
				W[i][j] = 0;
			}
		}
	}
}

int mulMatrix(int Arows, int Acols, int Bcols, double A[][200], double B[][200], double result[][200]) {
	for (int i=0; i<Arows; i++) {
		for (int j=0; j<Bcols;j++) {
			result[i][j] = 0;
			for (int k=0; k<Acols; k++) {
				result[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void powMatrix(int d, double A[][200], int n) {
	if (n==0) {
		for (int i=0; i<d; i++) {
			for (int j=0; j<d; j++) {
				if (i==j)
					A[i][j]=1;
				else
					A[i][j]=0;
			}
		}
		return;
	}
	if (n==1)
		return;
	double tmp[200][200];
	if (n%2 == 1) {
		for (int i=0; i<d; i++) {
			for (int j=0; j<d; j++) {
				tmp[i][j] = A[i][j];
			}
		}
		powMatrix(d, A, n/2);
		mulMatrix(d, d, d, A, A, resultTmp);
		mulMatrix(d, d, d, resultTmp, tmp, A);
	} else {
		powMatrix(d, A, n/2);
		mulMatrix(d, d, d, A, A, resultTmp);
		for (int i=0; i<d; i++) {
			for (int j=0; j<d; j++) {
				A[i][j] = resultTmp[i][j];
			}
		}
	}
}

int main() {
	int C;
	double sols[50][10];
	int solNumLikes[50];
	double tmp;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> numSongs >> K >> numLikes;
		solNumLikes[i] = numLikes;
		for (int j=0; j<numSongs; j++) {
			cin >> songLens[j];
		}
		for (int j=0; j<numSongs; j++) {
			for (int k=0; k<numSongs; k++) {
				cin >> nextProb[j][k];
			}
		}
		for (int j=0; j<numLikes; j++) {
			cin >> likeSongs[j];
		}
		makeW();
		powMatrix(numSongs*4, W, K);
		for (int j=0; j<numSongs*3; j++) {
			CMatrix[j][0] = 0;
		}
		for (int j=numSongs*3; j<numSongs*4; j++) {
			CMatrix[j][0] = 0;
		}
		CMatrix[numSongs*3][0] = 1;
		mulMatrix(numSongs*4, numSongs*4, 1, W, CMatrix, resultMatrix);
		for (int j=0; j<numLikes; j++) {
			tmp = 0;
			for (int k=0; k<songLens[likeSongs[j]]; k++) {
				tmp += resultMatrix[3*numSongs-k*numSongs + likeSongs[j]][0];
			}
			sols[i][j] = tmp;
		}
	}
	for (int i=0; i<C; i++) {
		for (int j=0; j<solNumLikes[i]; j++) {
			cout << fixed<<setprecision(10)<<sols[i][j];
			if (j+1 != solNumLikes[i])
				cout << " ";
		}
		cout << endl;
	}

}
