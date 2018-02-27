// Retrospection:
// 1. Good tip to find solution in dictionary order or smallest one first: search in dictionary order.
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

int N, M;
vector<int> availDigits;
int prevS[20000];
int choice[20000];

void init() {
	memset(prevS, -1, sizeof(prevS));
}

int append(int s, int d) {
	if (N<=s*10+d) return (s*10+d)%N + N;
	else return (s*10+d)%N;
}

void printSolution() {
	int cur = M+N;
	vector<int> choices;
	while (prevS[cur] != cur) {
		choices.push_back(choice[cur]);
		cur = prevS[cur];
	}
	reverse(choices.begin(), choices.end());
	for (int i=0; i<choices.size(); i++)
		cout << choices[i];
	cout <<endl;
}

void solve(string& availNumStr) {
	init();
	availDigits.clear();
	for (int i=0; i<availNumStr.size(); i++) {
		availDigits.push_back(availNumStr[i] - '0');
	}
	sort(availDigits.begin(), availDigits.end());
	queue<int> q;
	prevS[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i=0; i<availDigits.size(); i++) {
			int digit = availDigits[i];
			int there = append(here, digit);
			if (prevS[there] == -1) {
				q.push(there);
				prevS[there] = here;
				choice[there] = digit;
			}
			if (there == M+N) {
				printSolution();
				return;
			}
		}
	}
	cout << "IMPOSSIBLE" <<endl;
}

int main() {
	int C;
	string availNumStr;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> availNumStr >> N >> M;
		solve(availNumStr);
	}
}
