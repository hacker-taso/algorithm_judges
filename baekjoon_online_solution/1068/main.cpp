#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	enum Etc{Root=-1, Deleted=-2};
	vector<int> parent(N);
	for (int i=0; i<N; i++) {
		cin >> parent[i];
	}
	int deleted;
	cin >> deleted;
	parent[deleted] = Deleted;

	int walk;
	for (int node=0; node<N; node++) {
		walk = node;
		while (1) {
			if (parent[walk] == Root)
				break;
			else if (parent[walk] == Deleted) {
				parent[node] = Deleted;
				break;
			} else {
				walk = parent[walk];
			}
		}
	}
	
	vector<bool> leafMap(N, true);
	for (int node=0; node<N; node++) {
		walk = node;
		while (1) {
			if (parent[walk] == Root) {
				break;
			} else if (parent[walk] == Deleted) {
				leafMap[walk] = false;
				break;
			} else {
				leafMap[parent[walk]] = false;
				walk = parent[walk];
			}
		}
	}
	cout << count(leafMap.begin(), leafMap.end(), true) << endl;
}

