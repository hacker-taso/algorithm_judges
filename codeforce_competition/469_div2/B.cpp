#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> seq1(n);
	for (int i=0; i<n; i++)
		cin >> seq1[i];
	int tmp;
	int sol = 0;
	int diff = 0;
	int oneIdx = 0;
	for (int i=0; i<m; i++) {
		cin >> tmp;
		diff -= tmp;
		while (diff < 0) {
			diff += seq1[oneIdx++];
		}
		if (diff == 0)
			sol++;
	}
	cout << sol << endl;
}
