// I've read the editorial.
// Start at 10:03AM March 06, 2018
// End at 05:44PM March 06, 2018 (I spent about 2 hours.)
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
char newBoard[100][100];
char board[100][100];
bool rooks[100][100];
bool bishops[100][100];


void fillRooks() {
	bool canFillY[100], canFillX[100];
	memset(canFillX, 1, sizeof(canFillX));
	memset(canFillY, 1, sizeof(canFillY));
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			if (rooks[y][x]) {
				canFillY[y] = false;
				canFillX[x] = false;
			}
		}
	}
	for (int y=0; y<N; y++) {
		if (canFillY[y]) {
			for (int x=0; x<N; x++) {
				if (canFillX[x]) {
					rooks[y][x] = true;
					canFillY[y] = false;
					canFillX[x] = false;
					break;
				}
			}
		}
	}
}

const int dy[] = {1, 1};
const int dx[] = {1, -1};
int ids[2][100][100];
// dir1 id, dir2 id => y axis
int idToPosY[200][200];
int idToPosX[200][200];
bool adjMat[200][200];
int idCnt[2];
// dir, id
int matches[2][200];
bool cantchange[2][200];
// for bipartiteMatch
int visited[200];

bool bipartiteMatch(int a) {
	if (visited[a] || cantchange[0][a]) return false;
	visited[a] = true;
	for (int b=0; b<idCnt[1]; b++) {
		if (cantchange[1][b]) continue;
		if (adjMat[a][b]) {
			if (matches[1][b] == -1 || bipartiteMatch(matches[1][b])) {
				matches[1][b] = a;
				matches[0][a] = b;
				return true;
			}
		}
	}
	return false;
}

void fillBishops() {
	bool added[2][100][100] = {0};
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			for (int dir=0; dir<2; dir++) {
				if (added[dir][y][x]) continue;
				for (int yIt = y, xIt=x; 0<=yIt && yIt<N && 0<=xIt && xIt<N; yIt+=dy[dir], xIt+=dx[dir]) {
					added[dir][yIt][xIt] = true;
					ids[dir][yIt][xIt] = idCnt[dir];
				}
				idCnt[dir]++;
			}
		}
	}
	for (int y=0; y<N; y++) {
		for (int x=0; x<N; x++) {
			idToPosY[ids[0][y][x]][ids[1][y][x]] = y;
			idToPosX[ids[0][y][x]][ids[1][y][x]] = x;
			adjMat[ids[0][y][x]][ids[1][y][x]] = 1;
			if (bishops[y][x]) {
				cantchange[0][ids[0][y][x]] = true;
				cantchange[1][ids[1][y][x]] = true;
				matches[0][ids[0][y][x]] = ids[1][y][x];
				matches[1][ids[1][y][x]] = ids[0][y][x];
			}
		}
	}
	// dir 0: a, dir 1: b (from a to b bipartitle match)
	for (int a=0; a<idCnt[0]; a++) {
		memset(visited, 0, sizeof(visited));
		bipartiteMatch(a);
	}
	for (int a=0; a<idCnt[0]; a++) {
		if (matches[0][a] == -1) continue;
		int b = matches[0][a];
		bishops[idToPosY[a][b]][idToPosX[a][b]] = true;
	}
}

void init() {
	memset(newBoard, 0, sizeof(newBoard));
	memset(board, 0, sizeof(board));
	memset(rooks, 0, sizeof(rooks));
	memset(bishops, 0, sizeof(bishops));
	memset(ids, 0, sizeof(ids));
	memset(matches, -1, sizeof(matches));
	memset(idCnt, 0, sizeof(idCnt));
	memset(idToPosY, -1, sizeof(idToPosY));
	memset(idToPosX, -1, sizeof(idToPosX));
	memset(cantchange, 0, sizeof(cantchange));
	memset(adjMat, 0, sizeof(adjMat));
}

int main() {
	int C;
	char cTmp;
	int y, x;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> N >> M;
		for (int j=0; j<M; j++) {
			cin >> cTmp >> y >> x;
			if (cTmp == 'o') {
				rooks[y-1][x-1] = 1;
				bishops[y-1][x-1] = 1;
			} else if (cTmp == 'x') {
				rooks[y-1][x-1] = 1;
			} else if (cTmp == '+') {
				bishops[y-1][x-1] = 1;
			}
			board[y-1][x-1] = cTmp;
		}
		fillRooks();
		fillBishops();
		int changeCnt = 0;
		int point = 0;
		for (y=0; y<N; y++) {
			for (x=0; x<N; x++) {
				if (rooks[y][x] && bishops[y][x]) {
					newBoard[y][x] = 'o';
					point+=2;
				}
				else if (rooks[y][x]) {
					newBoard[y][x] = 'x';
					point++;
				}
				else if (bishops[y][x]) {
					newBoard[y][x] = '+';
					point++;
				}
				if (newBoard[y][x] != board[y][x])
					changeCnt++;
			}
		}
		cout << "Case #" << i+1 << ": " << point << " " << changeCnt << endl;
		for (int y=0; y<N; y++) {
			for (int x=0; x<N; x++) {
				if (newBoard[y][x] != board[y][x]) {
					cout << newBoard[y][x] << " " << y+1 << " " << x+1 <<endl;
				}
			}
		}
	}
}
