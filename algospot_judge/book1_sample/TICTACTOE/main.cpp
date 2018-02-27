#include<iostream>
#include<vector>
#define WIN 1
#define DRAW 0
#define LOSE -1
using namespace std;

char board[3][3];
int boardInt;

char getTurn() {
	int numO = 0;
	int numX = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			numO += (board[i][j]=='o');
			numX += (board[i][j]=='x');
		}
	}
	return numO < numX ? 'o' : 'x';
}

char whoWin(char board[3][3]) {
	for (int i=0; i<3; i++) {
		char first = board[i][0];
		int j=1;
		for (; j<3; j++) {
			if (first != board[i][j]) break;
		}
		if (j==3 && first != '.') return first;
		first = board[0][i];
		j=1;
		for (; j<3; j++) {
			if (first != board[j][i]) break;
		}
		if (j==3 && first != '.') return first;
	}
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
		board[0][2] == board[1][1] && board[1][1] == board[2][0]) && board[1][1] != '.') {
		return board[1][1];
	}
	return '?';
}

int canWin(char board[3][3], bool isOTurn) {
	char winner = whoWin(board);
	if (winner != '?') {
		if (isOTurn) {
			if (winner == 'o') return WIN;
			else return LOSE;
		} else {
			if (winner == 'x') return WIN;
			else return LOSE;
		}
	}
	char nextBlock = isOTurn ? 'o' : 'x';
	int canWinVal;
	bool canDRAW = false;
	bool canPlay = false;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (board[i][j] != '.') continue;
			canPlay = true;
			board[i][j] = nextBlock;
			canWinVal = canWin(board, !isOTurn);
			board[i][j] = '.';
			if (canWinVal == LOSE) return WIN;
			if (canWinVal == DRAW) canDRAW = true;
		}
	}
	if (canPlay==false || canDRAW == true)
		return DRAW;
	else
		return LOSE;
}

char solve() {
	bool isOTurn = getTurn() == 'o';
	int canWinVal = canWin(board, isOTurn);
	if (canWinVal == DRAW)
		return 0;
	else if (canWinVal == WIN) {
		if (isOTurn) return 'o';
		else return 'x';
	} else {
		if (isOTurn) return 'x';
		else return 'o';
	}
}

int main() {
	int C;
	string tmp;
	vector<char> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		for (int j=0; j<3; j++) {
			cin >> tmp;
			for (int k=0; k<3; k++) {
				board[j][k] = tmp[k];
			}
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		if (sols[i] == 'o' || sols[i] == 'x')
			cout << sols[i] <<endl;
		else
			cout << "TIE" << endl;
	}
}
