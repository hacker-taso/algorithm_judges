#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int cache[10][5][5];
char board[25][25];

const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void cacheInit() {
	memset(cache, -1, sizeof(cache));
}

bool canFind(const string& word, int wordIdx, int y, int x) {
	if (y<0 || 5<=y || x<0 || 5<=x)
		return false;
	int& ret = cache[wordIdx][y][x];
	if (ret != -1) return ret;
	if (word[wordIdx] != board[y][x])  {
		ret = false;
		return ret;
	}
	if (wordIdx == word.size()-1) {
		ret = true;
		return ret;
	}
	for (int i=0; i<8; i++)
		if (canFind(word, wordIdx+1, y+dy[i], x+dx[i])) {
			ret = true;
			return ret;
		}
	ret = false;
	return ret;
}

bool solve(const string& word) {
	for (int i=0; i<5; i++)
		for (int j=0; j<5; j++)
			if (canFind(word, 0, i, j))
				return true;
	return false;
}

int main() {
	int C, numWord;
	string tmp;
	vector<string> words;
	vector<bool> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		for (int j=0; j<5; j++) {
			cin >> tmp;
			for (int k=0; k<5; k++)
				board[j][k] = tmp[k];
		}
		cin >> numWord;
		for (int j=0; j<numWord; j++) {
			cacheInit();
			cin >> tmp;
			words.push_back(tmp);
			sols.push_back(solve(tmp));
		}
	}
	for (int i=0; i<words.size(); i++) {
		cout << words[i] << " ";
		if (sols[i])
			cout << "YES" <<endl;
		else
			cout << "NO" << endl;
	}
}
