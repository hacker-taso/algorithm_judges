#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int countBool(vector<vector<bool>> boolMap, int xs, int xe, int ys, int ye, bool b) {
	int cnt = 0;
	for (int i=xs; i<=xe; i++) {
		for (int j=ys; j<=ye; j++) {
			if (boolMap[i][j] == b) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> board(N);
	for (int i=0; i<N; i++) {
		cin >> board[i];
	}

	string wline;
	string bline;
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (j%2 == 0) {
				wline += "W";
				bline += "B";
			} else {
				wline += "B";
				bline += "W";
			}
		}
	}
	vector<string> wboard(N);
	for (int i=0; i<N; i++) {
		if (i%2 == 0)
			wboard[i] = wline;
		else
			wboard[i] = bline;
	}

	vector<vector<bool>> wboardMap(N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (wboard[i][j] == board[i][j])
				wboardMap[i].push_back(true);
			else
				wboardMap[i].push_back(false);
		}
	}

	// cntW: count if make the board to wboard which is the board that start with white
	// cntB: count if make the board to bboard which is the board that start with black
	int min = INT_MAX;
	int cntW, cntB;
	for (int i=0; i+7<N; i++) {
		for (int j=0; j+7<M; j++) {
			cntW = countBool(wboardMap, i, i+7, j, j+7, true);
			cntB = countBool(wboardMap, i, i+7, j, j+7, false);
			min = (min < cntB ? min : cntB);
			min = (min < cntW ? min : cntW);
		}
	}
	cout << min << endl;
}

