#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
char cache[1<<25];
vector<int> moves;

void programInit() {
	for (int y=0; y<5; y++) {
		for (int x=0; x<5; x++) {
			if (x != 4)
				moves.push_back( (1<<(y*5+x)) | (1<<(y*5+x+1)) );
			if (y != 4)
				moves.push_back( (1<<(y*5+x)) | (1<<((y+1)*5 + x)) );
		}
	}
	for (int y=0; y<5; y++) {
		for (int x=0; x<5; x++) {
			if (x != 4 && y != 4) {
				moves.push_back( (1<<(y*5+x)) | (1<<(y*5+x+1)) | (1<<((y+1)*5+x)) );
				moves.push_back( (1<<(y*5+x)) | (1<<((y+1)*5+x)) | (1<<((y+1)*5+x+1)) );
				moves.push_back( (1<<(y*5+x)) | (1<<(y*5+x+1)) | (1<<((y+1)*5+x+1)) );
			}
			if (x != 0 && y != 4) {
				moves.push_back( (1<<(y*5+x)) | (1<<((y+1)*5+x)) | (1<<((y+1)*5+x-1)) );
			}
		}
	}
}

void testInit() {
	memset(cache, -1, sizeof(cache));
}

char canWin(int map) {
	char& ret = cache[map];
	if (ret != -1) return ret;

	for (int i=0; i<moves.size(); i++) {
		if ((moves[i] & map) == 0) {
			if (canWin(moves[i] | map) == false) {
				ret = true;
				return ret;
			}
		}
	}
	ret = false;
	return ret;
}

int main() {
	int C, sols[50];
	string tmp;
	int map;
	cin >> C;
	programInit();
	for (int i=0; i<C; i++) {
		testInit();
		map = 0;
		for (int j=0; j<5; j++) {
			cin >> tmp;
			for (int k=0; k<5; k++) {
				if (tmp[k] == '#')
					map |= 1 << (j*5+k);
			}
		}
		sols[i] = canWin(map);
	}
	for (int i=0; i<C; i++) {
		if (sols[i])
			cout << "WINNING" << endl;
		else
			cout << "LOSING" << endl;
	}
}
