// Wrong answer Note: I thought parent should install a camera when not all children install the camera.
// But it is not true, if all children are watched then it would be enough.
#include<iostream>
#include<vector>
#include<cstring>
// installed
#define INSTALLED 0
// watched because child installed
#define WATCHED 1
// unwatched, so parent should install
#define UNWATCHED 2
using namespace std;

int numCameras, numGalleries, numHallways;
vector< vector<int> > adjList;
bool visited[1000];

int search(int n) {
	visited[n] = 1;
	bool watched = false;
	bool allChildWatched = true;
	vector<int>& curAdjs = adjList[n];
	for (int i=0; i<curAdjs.size(); i++) {
		if (visited[curAdjs[i]]) continue;
		switch (search(curAdjs[i])) {
		case UNWATCHED:
			allChildWatched = false;
			break;
		case INSTALLED: // children watched
			watched = true;
			break;
		default:
			break;
		}
	}

	if (!allChildWatched) { // should install
		numCameras++;
		return INSTALLED;
	} else if (watched) // not need to install
		return WATCHED;
	else {
		return UNWATCHED;
	}
}

int solve() {
	numCameras = 0;
	memset(visited, 0, sizeof(visited));
	for (int i=0; i<numGalleries; i++) {
		if (visited[i]) continue;
		switch (search(i)) {
		case UNWATCHED:
			numCameras++;
		default:
			break;
		}
	}
	return numCameras;
}

int main() {
	vector <int> sols;
	int C, tmp1, tmp2;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numGalleries >> numHallways;
		adjList.clear();
		adjList.resize(numGalleries);
		for (int j=0; j<numHallways; j++) {
			cin >> tmp1 >> tmp2;
			adjList[tmp1].push_back(tmp2);
			adjList[tmp2].push_back(tmp1);
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
