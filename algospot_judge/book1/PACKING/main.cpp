#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
void testInit();
int getMaxImportance(int, int);
void reconstruct(int object, int currVolume, vector<string>& solObjectStr);
// initial values
int numObjects, maxVolume;
string objectNames[100];
int volumes[100];
int importances[100];

// result
int cache[1001][100];

int main() {
	int C;
	cin >> C;
	int solMaxImportances[50];
	vector<string> solObjects[50];
	for (int i=0; i<C; i++) {
		testInit();
		cin >> numObjects >> maxVolume;
		for (int j=0; j<numObjects; j++) {
			cin >> objectNames[j] >> volumes[j] >> importances[j];
		}
		solMaxImportances[i] = getMaxImportance(0, 0);
		reconstruct(0, 0, solObjects[i]);
	}
	for (int i=0; i<C; i++) {
		cout << solMaxImportances[i] << " " << solObjects[i].size() << endl;
		for (int j=0; j<solObjects[i].size(); j++) {
			cout << solObjects[i][j] << endl;
		}
	}
}

void testInit() {
	memset(cache, -1, sizeof(cache));
}

int getMaxImportance(int currVolume, int currObject) {
	if (currObject == numObjects)
		return 0;
	int& ret = cache[currVolume][currObject];
	if (ret != -1) return ret;
	if (currVolume+volumes[currObject] <= maxVolume) {
		int takeImp = getMaxImportance(currVolume+volumes[currObject], currObject+1) + importances[currObject];
		int notTakeImp = getMaxImportance(currVolume, currObject+1);
		ret = max(takeImp, notTakeImp);
	} else {
		ret = getMaxImportance(currVolume, currObject+1);
	}
	return ret;
}

void reconstruct(int object, int currVolume, vector<string>& solObjectStr) {
	if (object == numObjects)
		return;
	if (getMaxImportance(currVolume, object) == getMaxImportance(currVolume, object+1)) {
		reconstruct(object+1, currVolume, solObjectStr);
	} else {
		solObjectStr.push_back(objectNames[object]);
		reconstruct(object+1, currVolume + volumes[object], solObjectStr);
	}
}
