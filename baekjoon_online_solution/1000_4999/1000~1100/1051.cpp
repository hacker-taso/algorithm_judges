#include<iostream>
using namespace std;
int main(){
	int N,M;
	cin >> N >> M;
	int ** rect = new int*[N];
	string rectStr;
	for (int i=0; i<N; i++) {
		rect[i] = new int[M];
		cin >> rectStr;
		for(int j=0; j<M; j++) {
			rect[i][j] = rectStr[j] - '0';
		}
	}
	
	int minSide = N < M ? N : M;
	int nw, ne, sw, se;
	int maxLen = 1;
	for (int len=1; len <= minSide; len++) {
		for (int n=0; n+len < N; n++) {
			for (int m=0; m+len < M; m++) {
				nw = rect[n][m];
				ne = rect[n][m+len];
				sw = rect[n+len][m];
				se = rect[n+len][m+len];
				if (nw == ne && nw == sw && nw == se)
					maxLen = len+1;
			}
		}
	}
	cout << maxLen*maxLen << endl;
}

