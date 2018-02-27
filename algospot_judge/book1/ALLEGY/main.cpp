// Retrospect: I did try to use bitmask to express set.
// But it rather made the program slow.
// It was better to use linked list.
// I think it's because when I use linked list, each linked list has very small amount of elements. 
// (with bitmask, I should iterate all bit to check whether it is set or not)
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<cassert>
#define INF 0x76543210
#define NO_HOPE -1
using namespace std;

int friendCnt, foodCnt;
// can eat:1 cannot eat:0
int foodFriendMap[50][50];
// friends which can eat this food. key: food
vector<int> likers[50];
// foods which can be eaten by this friend. key: friend
vector<int> canEat[50];
int minSolution;

void init() {
	minSolution = INF;
	for (int i=0; i<50; i++) {
		likers[i].clear();
		canEat[i].clear();
	}
	memset(foodFriendMap, 0, sizeof(foodFriendMap));
}

void solve(const int numFoods, vector<int>& numEdible) {
	if (minSolution<=numFoods) return;
	int i=0;
	while(i<numEdible.size() && numEdible[i] != 0) i++;
	if (i==numEdible.size()) {
		minSolution = numFoods;
		return;
	}
	const vector<int>& availFoods = canEat[i];
	for (i=0; i<availFoods.size(); i++) {
		const vector<int>& liker = likers[availFoods[i]];
		for (int j=0; j<liker.size(); j++) {
			numEdible[liker[j]]++;
		}
		solve(numFoods+1, numEdible);
		for (int j=0; j<liker.size(); j++) {
			numEdible[liker[j]]--;
		}
	}
}

int main() {
	int C;
	vector<int> sols;
	string friendNames[50];
	cin >> C;
	int friendCntTmp = 0;
	string friendNameTmp;
	sols.resize(C, 0);
	for (int i=0; i<C; i++) {
		init();
		cin >>friendCnt >> foodCnt;
		for (int j=0; j<friendCnt; j++) {
			cin >> friendNames[j];
		}
		for (int j=0; j<foodCnt; j++) {
			cin >> friendCntTmp;
			for (int k=0; k<friendCntTmp; k++) {
				cin >> friendNameTmp;
				foodFriendMap[j][distance(friendNames, find(friendNames, friendNames+friendCnt, friendNameTmp))] = 1;
			}
		}
		for (int j=0; j<foodCnt; j++) {
			for (int k=0; k<friendCnt; k++) {
				if (foodFriendMap[j][k]) {
					likers[j].push_back(k);
					canEat[k].push_back(j);
				}
			}
		}
		vector<int> numEdible(friendCnt, 0);
		solve(0, numEdible);
		sols[i] = minSolution;
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
