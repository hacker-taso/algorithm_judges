#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k, m, tmp2;
	cin >> n >> k >> m;
	string tmp;
	map<string, int> wordToIdx;
	for (int i=0; i<n; i++) {
		cin >> tmp;
		wordToIdx[tmp] = i;
	}
	vector<int> costs(n);
	for (int i=0; i<n; i++) {
		cin >> costs[i];
	}
	vector<int> smallest(n);
	for (int i=0; i<k; i++) {
		cin >> tmp2;
		vector<int> groups = vector<int>(tmp2);
		int small = 0x76543210;
		for (int j=0; j<tmp2; j++) {
			cin >> groups[j];
			small = min(costs[groups[j]-1], small);
		}
		for (int j=0; j<tmp2; j++)
			smallest[groups[j]-1] = small;
	}
	long long sum = 0;
	for (int i=0; i<m; i++) {
		cin >> tmp;
		sum+=smallest[wordToIdx[tmp]];
	}
	cout << sum << endl;
}
