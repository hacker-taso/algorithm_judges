#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N;
vector< vector<char> > board;
int id[2][8][8];
const int dx[2] = {1, -1};
const int dy[2] = {1, 1};
vector<int> bMatch;
vector< vector<bool> > adjMat;
int counters[2];
vector<bool> visited;

bool dfs(int n) {
	if (visited[n]) return false;
	visited[n] = true;
	for (int i=0; i<counters[1]; i++) {
		if (adjMat[n][i]) {
			if (bMatch[i] == -1 || dfs(bMatch[i])) {
				bMatch[i] = n;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch() {
	bMatch.clear();
	bMatch.resize(counters[1], -1);
	int totalMatch = 0;
	for (int i=0; i<counters[0]; i++) {
		visited.clear();
		visited.resize(counters[0], false);
		if (dfs(i)) {
			totalMatch++;
		}
	}
	return totalMatch;
}

int solve() {
	memset(id, -1, sizeof(id));
	memset(counters, 0, sizeof(counters));
	for (int dir=0; dir<2; dir++) {
		for (int j=0; j<N; j++) {
			for (int i=0; i<N; i++) {
				if (board[i][j] == '*' || id[dir][i][j] != -1) continue;
				int x = i;
				int y = j;
				while (0<=x && x<N && 0<=y && y<N && board[x][y] != '*') {
					id[dir][x][y] = counters[dir];
					x+=dx[dir];
					y+=dy[dir];
				}
				counters[dir]++;
			}
		}
	}
	adjMat.clear();
	adjMat.resize(counters[0], vector<bool>(counters[1], false));
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (board[i][j] == '.') {
				adjMat[id[0][i][j]][id[1][i][j]] = true;
			}
		}
	}
	return bipartiteMatch();
}

int main() {
	int C;
	vector<int> sols;
	string tmp;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> N;
		board.clear();
		board.resize(N, vector<char>(N));
		for (int j=0; j<N; j++) {
			cin >> tmp;
			for (int k=0; k<N; k++)
				board[j][k] = tmp[k];
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
