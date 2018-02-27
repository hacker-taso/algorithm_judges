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
long long likers[50];
// foods which can be eaten by this friend. key: friend
long long canEat[50];
map<long long,bool> tried[51][6];
int minSolution;
int biggestCoverSize;

int getBestFood(const long long coverState, const long long allTriedFoods, const int frend) {
	int bestFood;
	int maxCover = -1;
	long long availFoods = canEat[frend];
	for (;availFoods; availFoods -= (-availFoods & availFoods)) {
		int food = __builtin_ctzll(availFoods);
		if (allTriedFoods & (1ll<<food)) continue;
		long long notCovered = (~coverState) & ((1ll<<friendCnt)-1);
		int numCanCover = __builtin_popcountll(likers[food] & notCovered);
		if (maxCover < numCanCover) {
			maxCover = numCanCover;
			bestFood = food;
		}
	}
	if (maxCover <= 0) return NO_HOPE;
	return bestFood;
}

int getBestFriend(const long long triedFoods, const long long triedFriends) {
	int bestFriend;
	int minLikes = INF;
	for (int i=0; i<friendCnt; i++) {
		if (triedFriends & (1ll<<i)) continue;
		long long notTried = (~triedFoods) & ((1ll<<foodCnt)-1);
		int numLikes = __builtin_popcountll(canEat[i] & notTried);
		if (numLikes!=0 && numLikes<minLikes) {
			bestFriend = i;
			minLikes = numLikes;
		}
	}
	if (minLikes == INF) return NO_HOPE; // all numLikes are zero.
	return bestFriend;
}

void init() {
	minSolution = INF;
	memset(likers, 0, sizeof(likers));
	memset(foodFriendMap, 0, sizeof(foodFriendMap));
	memset(canEat, 0, sizeof(canEat));
	for (int i=0; i<51; i++) {
		for (int j=0; j<6; j++)
			tried[i][j].clear();
	}
}

void solve(const int numFoods, const long long triedFoods, const long long coverState) {
	int notCoveredNum = __builtin_popcountll((~coverState)&((1ll<<friendCnt)-1));
	if (minSolution <= numFoods+notCoveredNum/biggestCoverSize) return;
	int coveredNum = __builtin_popcountll(coverState);
	if (numFoods<6 && 0<tried[coveredNum][numFoods].count(triedFoods)) return;
	if (coveredNum == friendCnt) {
		minSolution = numFoods;
		return;
	}
	long long curTriedFoods = 0;
	long long curTriedFriends = 0;
	for (int i=0; i<friendCnt; i++) {
		int frend = getBestFriend(triedFoods, curTriedFriends);
		if (frend == NO_HOPE) return;
		curTriedFriends |= 1ll<< frend;
		int food = getBestFood(coverState, triedFoods | curTriedFoods, frend);
		if (food == NO_HOPE) continue;
		curTriedFoods |= 1ll<<food;
		solve(numFoods+1, triedFoods|(1ll<<food), likers[food] | coverState);
		coveredNum = __builtin_popcountll(likers[food] | coverState);
		if (numFoods+1<6)
			tried[coveredNum][numFoods+1][triedFoods|(1ll<<food)] = true;
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
				likers[j] |= ((long long)foodFriendMap[j][k]<<k);
			}
		}
		for (int j=0; j<friendCnt; j++) {
			for (int k=0; k<foodCnt; k++) {
				canEat[j] |= ((long long)foodFriendMap[k][j]<<k);
			}
		}
		biggestCoverSize = 0;
		for (int j=0; j<foodCnt; j++) {
			biggestCoverSize = max(biggestCoverSize, __builtin_popcountll(likers[j]));
		}
		solve(0, 0, 0);
		sols[i] = minSolution;
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
