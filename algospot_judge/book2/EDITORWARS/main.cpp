// Retrospection:
// 1. (mistake) Wrongly understood the problem.
#include<iostream>
#include<vector>
#include<set>
#define ACK true
#define CONTRA false
using namespace std;
const string ACK_STR="ACK";
const string CONTRA_STR="DIS";

struct DISJOINT_SET {
	vector<int> ranks;
	vector<int> sets;
	vector<int> sizes;
	vector<int> enemies;
	DISJOINT_SET(int n): sets(n), ranks(n, 1), sizes(n, 1), enemies(n, -1) {
		for (int i=0; i<n; i++) sets[i] = i;
	}
	int find(int v) {
		if (v == -1) return -1;
		if (sets[v] == v) return v;
		int r = find(sets[v]);
		sets[v] = r;
		return r;
	}
	int merge(int v1, int v2) {
		int root1 = find(v1);
		int root2 = find(v2);
		if (root1 == -1 && root2 == -1) return root1;
		else if (root1 == -1) return root2;
		else if (root2 == -1) return root1;
		if (root1 == root2) return root1;
		if (ranks[root1] == ranks[root2]) {
			sets[root2] = root1;
			ranks[root1] += 1;
			sizes[root1] += sizes[root2];
			return root1;
		} else if (ranks[root1] < ranks[root2]) {
			sets[root1] = root2;
			sizes[root2] += sizes[root1];
			return root2;
		}
		else {
			sets[root2] = root1;
			sizes[root1] += sizes[root2];
			return root1;
		}
	}
	int size(int v) {
		return sizes[find(v)];
	}
	int enemySize(int v) {
		int enemy = enemies[find(v)];
		if (enemy == -1)
			return 0;
		return sizes[find(enemy)];
	}
	// return false if contradict
	bool ack(int v1, int v2) {
		int r1 = find(v1);
		int r2 = find(v2);
		if (enemies[r1] == r2) {
			return false;
		}
		int newR = merge(r1, r2);
		int newEnemy = merge(enemies[r1], enemies[r2]);
		enemies[newR] = newEnemy;
		if (newEnemy != -1)
			enemies[newEnemy] = newR;
		return true;
	}
	// return false if contradict
	bool dis(int v1, int v2) {
		int r1 = find(v1);
		int r2 = find(v2);
		if (r1 == r2) return false;
		int enemy1 = enemies[r1];
		int enemy2 = enemies[r2];
		int newR1 = merge(r1, enemy2);
		int newR2 = merge(r2, enemy1);
		enemies[newR1] = newR2;
		enemies[newR2] = newR1;
		return true;
	}
};

pair<bool, int> solve(int numMember, int numComment) {
	int p1, p2;
	string type;
	DISJOINT_SET ds(numMember);
	int contraDictIdx = -1;
	for (int i=1; i<=numComment; i++) {
		cin >> type >> p1 >> p2;
		if (type == ACK_STR) {
			if (!ds.ack(p1, p2) && contraDictIdx == -1) {
				contraDictIdx = i;
			}
		}
		else {
			if (!ds.dis(p1, p2) && contraDictIdx == -1) {
				contraDictIdx = i;
			}
		}
	}
	if (contraDictIdx != -1)
		return pair<bool, int>(CONTRA, contraDictIdx);
	int minSize = 0;
	for (int i=0; i<numMember; i++) {
		if (ds.sets[i] != i) continue;
		if (i<ds.enemies[i]) continue;
		minSize+=max(ds.size(i), ds.enemySize(i));
	}
	return pair<bool, int>(ACK, minSize);
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, numMember, numComment;
	vector< pair<bool, int> > sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numMember >> numComment;
		sols.push_back(solve(numMember, numComment));
	}
	for (int i=0; i<C; i++) {
		if (sols[i].first == ACK)
			cout << "MAX PARTY SIZE IS " << sols[i].second << endl;
		else
			cout << "CONTRADICTION AT " << sols[i].second << endl;
	}
}
