#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

struct Node {
	int x, y, r;
	vector<Node*> children;
	Node(int _x, int _y, int _r) {x=_x;y=_y;r=_r;}
};

Node* root;

// O(N) -> total O(N^2)
void insert(Node* root, int x, int y, int r) {
	double centerDist;
	vector<Node*> includes;
	for (vector<Node*>::iterator it = root->children.begin(); it!=root->children.end(); it++) {
		Node* insideN = (*it);
		centerDist = hypot(insideN->x - x, insideN->y - y);
		if (centerDist+r < insideN->r) { // included
			insert(insideN, x, y, r);
			return;
		} else if (centerDist + insideN->r < r) { // includes
			includes.push_back(insideN);
			root->children.erase(it);
			it--;
		}
	}
	Node* n = new Node(x,y,r);
	n->children = includes;
	root->children.push_back(n);
}

// O(N)
int getHeight(Node*root) {
	if (root->children.empty())
		return 0;
	int height = 0;
	for (int i=0; i<root->children.size(); i++) {
		height = max(height, getHeight(root->children[i])+1);
	}
	return height;
}

// O(N^3). If we memoize height, this could be O(N^2) (getHeight can be O(N) in total and constant time in one call)
// if we also memoize maxPathLen, this could be O(N) (execute all children twice, the number of all children is O(N))
int getMaxPathLen(Node*root) {
	if (root->children.empty())
		return 0;
	int maxHeight = 0;
	int secondHeight = 0;
	int height;
	// O(N^2)
	for (int i=0; i<root->children.size(); i++) {
		height = getHeight(root->children[i]) + 1;
		if (maxHeight <= height) {
			secondHeight = maxHeight;
			maxHeight = height;
		} else if (secondHeight < height) {
			secondHeight = height;
		}
	}
	int maxPathLen = maxHeight+secondHeight;
	for (int i=0; i<root->children.size(); i++) {
		maxPathLen = max(maxPathLen, getMaxPathLen(root->children[i]));
	}
	return maxPathLen;
}

int main() {
	int C, sols[100], x, y, r, numFort;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numFort;
		cin >> x >> y >> r;
		root = new Node(x, y, r);
		for (int j=1; j<numFort; j++) {
			cin >> x >> y >> r;
			insert(root, x, y, r);
		}
		sols[i] = getMaxPathLen(root);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
