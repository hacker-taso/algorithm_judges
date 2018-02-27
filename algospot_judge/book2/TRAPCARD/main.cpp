#include<iostream>
#include<vector>
#include<cstring>
#define EMPTY '.'
#define WALL '#'
#define TRAP '^'
using namespace std;

int id[20][20];
bool adj[400][400];
int numA, numB;
char board[20][20];
int H, W;

bool isInBound(int y, int x) {
	return 0<=y && 0<=x && y<H && x<W;
}

void makeAdj() {
	const int dx[] = {-1, 1, 0, 0};
	const int dy[] = {0, 0, -1, 1};
	memset(adj, 0, sizeof(adj));
	memset(id, -1, sizeof(id));
	numA = 0;
	numB = 0;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			if (board[i][j] == EMPTY) {
				if ((i+j)%2 == 0) {
					id[i][j] = numA++;
				} else {
					id[i][j] = numB++;
				}
			}
		}
	}
	for (int y=0; y<H; y++) {
		for (int x=0; x<W; x++) {
			if (id[y][x] == -1) continue;
			for (int k=0; k<4; k++) {
				int adjY = y+dy[k];
				int adjX = x+dx[k];
				if (!isInBound(adjY, adjX)) continue;
				if (id[adjY][adjX] == -1) continue;
				adj[id[y][x]][id[adjY][adjX]] = true;
			}
		}
	}
}

vector<bool> visited;
vector<int> aMatch, bMatch;

bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b=0; b<numB; b++) {
		if (adj[a][b]) {
			if (bMatch[b]==-1 || dfs(bMatch[b])) {
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch() {
	int numMatch = 0;
	aMatch = vector<int>(numA, -1);
	bMatch = vector<int>(numB, -1);
	for (int a=0; a<numA; a++) {
		if (aMatch[a]==-1) {
			visited.clear();
			visited.resize(numA, false);
			if (dfs(a))
				numMatch++;
		}
	}
	return numMatch;
}

void solve() {
	makeAdj();
	int maxMatch = bipartiteMatch();
	vector<bool> chosenA(numA, true);
	vector<bool> chosenB(numB, false);
	for (int i=0; i<numB; i++) {
		if (bMatch[i] == -1)
			chosenB[i] = true;
	}
	while (true) {
		bool changed = false;
		for (int a=0; a<numA; a++) {
			for (int b=0; b<numB; b++) {
				if (adj[a][b] && chosenA[a] && chosenB[b]) {
					chosenA[a] = false;
					chosenB[aMatch[a]] = true;
					changed = true;
				}
			}
		}
		if (!changed) break;
	}
	cout << numA+numB-maxMatch <<endl;
	for (int y=0; y<H; y++) {
		for (int x=0; x<W; x++) {
			if ((x+y)%2==0 && id[y][x]!=-1 && chosenA[id[y][x]]
				|| (x+y)%2 == 1 && id[y][x]!=-1 && chosenB[id[y][x]]) {
				cout << TRAP;
			} else {
				cout << board[y][x];
			}
		}
		cout <<endl;
	}
}

int main() {
	int C;
	string tmp;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> H >> W;
		for (int j=0; j<H; j++) {
			cin >> tmp;
			for (int k=0; k<W; k++) {
				board[j][k] = tmp[k];
			}
		}
		solve();
	}
}
