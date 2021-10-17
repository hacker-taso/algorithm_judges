#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const string yes = "Yes";
const string no = "No";
const char empty_cell = '.';
const char wall_cell = '#';
const char G = 'G';
const char B = 'B';

int n, m;
vector<string> board;
vector<vector<int>> adjList;
bool visited[2500];

void init() {
	memset(visited, 0, sizeof(visited));
}

int getGraphIdx(int i, int j) {
	return i*m + j;
}

void dfs(int cur) {
	visited[cur] = true;
	for (int i=0; i<adjList[cur].size(); i++){
		if (visited[adjList[cur][i]] == true)
			continue;
		dfs(adjList[cur][i]);
	}
}

string solve() {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++)
			if (board[i][j] == B) {
				if (0<i && board[i-1][j] == empty_cell)
					board[i-1][j] = wall_cell;
				if (0<i && board[i-1][j] == G)
					return no;
				if (0<j && board[i][j-1] == empty_cell)
					board[i][j-1] = wall_cell;
				if (0<j && board[i][j-1] == G)
					return no;
				if (i+1<n && board[i+1][j] == empty_cell)
					board[i+1][j] = wall_cell;
				if (i+1<n && board[i+1][j] == G)
					return no;
				if (j+1<m && board[i][j+1] == empty_cell)
					board[i][j+1] = wall_cell;
				if (j+1<m && board[i][j+1] == G)
					return no;
				board[i][j] = wall_cell;
			}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (board[i][j] == wall_cell)
				continue;
			if (j+1 < m && board[i][j+1] != wall_cell) {
				adjList[getGraphIdx(i, j)].push_back(getGraphIdx(i, j+1));
				adjList[getGraphIdx(i, j+1)].push_back(getGraphIdx(i, j));
			}
			if (i+1 < n && board[i+1][j] != wall_cell) {
				adjList[getGraphIdx(i, j)].push_back(getGraphIdx(i+1, j));
				adjList[getGraphIdx(i+1, j)].push_back(getGraphIdx(i, j));
			}
		}
	}
	dfs(getGraphIdx(n-1, m-1));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (board[i][j] == G && !visited[getGraphIdx(i, j)]) {
				return no;
			}
		}
	}
	return yes;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		init();
		cin >> n >> m;
		adjList = vector<vector<int>>(2500);
		board = vector<string>(n);
		for (int j=0; j<n; j++) {
			cin >> board[j];
		}
		cout << solve() << endl;
	}
}
