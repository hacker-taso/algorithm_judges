#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> positions(M);
	for (int i=0; i<M; i++) {
		cin >> positions[i];
		positions[i] -= 1;
	}
	vector<int> queue(N, 1);
	int goalPos, rmov, lmov;
	int curPos = 0;
	int movCnt = 0;
	for (int i=0; i<M; i++) {
		goalPos = positions[i];
		rmov = 0;
		for (int j=0; j<(goalPos-curPos+N)%N; j++) {
			rmov += queue[(curPos+j)%N];
		}
		lmov = 0;
		for (int j=1; j<=(curPos-goalPos+N)%N; j++) {
			lmov += queue[(curPos-j+N)%N];
		}
		queue[goalPos] = 0;
		movCnt += rmov < lmov ? rmov : lmov;
		curPos = goalPos;
	}
	cout << movCnt << endl;
}

