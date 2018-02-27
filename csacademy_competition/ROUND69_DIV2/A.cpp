// Pokemon fights
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> powers(N);
	for (int i=0; i<N; i++)
		cin >> powers[i];
	int winner = powers[0] < powers[1] ? 1 : 0;
	vector<int> wins(N, 0);
	wins[winner]++;
	for (int i=2; i<N; i++) {
		winner = powers[winner]<powers[i] ? i : winner;
		wins[winner]++;
	}
	for (int i=0; i<N; i++)
		cout << wins[i] << " ";
	cout <<endl;
}
