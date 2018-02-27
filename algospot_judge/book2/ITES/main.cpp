#include<iostream>
#include<queue>
#define MAX_LEN 50000000
using namespace std;

int seqLen, findingSum;
unsigned int before = 1983;

int getNext() {
	unsigned int next = (unsigned int)before * 214013 + 2531011;
	before = next;
	return next%10000 + 1;
}

int solve() {
	queue<int> q;
	int curSum = 0, sol = 0, curElem = 1983;
	for (int i=0; i<seqLen; i++) {
		q.push(curElem);
		curSum += curElem;
		while (findingSum<curSum) {
			curSum-=q.front();
			q.pop();
		}
		if (curSum==findingSum) {
			sol++;
		}
		curElem = getNext();
	}
	return sol;
}

int main() {
	int C, sols[20];
	cin >> C;
	for (int i=0; i<C; i++) {
		before = 1983;
		cin >> findingSum >> seqLen;
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}