#include<iostream>
using namespace std;

string quadtreeS;
string findPieceAndReverse(string);

int main() {
	int C;
	string sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> quadtreeS;
		sols[i] = findPieceAndReverse(quadtreeS);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

string findPieceAndReverse(string currStr) {
	if (currStr[0] == 'w' || currStr[0] == 'b') {
		return currStr.substr(0, 1);
	}
	string piece[4];
	int pos = 1;
	for (int i=0; i<4; i++) {
		piece[i] = findPieceAndReverse(currStr.substr(pos));
		pos += piece[i].size();
	}
	return "x" + piece[2] + piece[3] + piece[0] + piece[1];
}
