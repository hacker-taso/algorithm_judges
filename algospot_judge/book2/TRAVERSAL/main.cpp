#include<iostream>
#include<algorithm>
using namespace std;

int numNodes, preorder[100], inorder[100], postorder[100];

struct Node {
	int val;
	Node* left;
	Node*right;
	Node(int _val) {val = _val;}
	void setLeft(Node* n) { left = n; }
	void setRight(Node* n) { right = n;}
};

Node* makeTree(int ps, int is, int len) {
	if (len < 1)
		return NULL;
	int root = preorder[ps];
	int leftLen = find(inorder+is, inorder+is+len, root) - (inorder + is);
	Node* leftNode = makeTree(ps+1, is, leftLen);
	Node* rightNode = makeTree(ps+1+leftLen, is+leftLen+1, len-leftLen-1);
	Node* rootNode = new Node(root);
	rootNode->setLeft(leftNode);
	rootNode->setRight(rightNode);
	return rootNode;
}

void printPostOrder(Node* root) {
	if (root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout << root->val << " ";
}

void solve() {
	Node* root = makeTree(0, 0, numNodes);
	printPostOrder(root);
	cout << endl;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numNodes;
		for (int j=0; j<numNodes; j++) {
			cin >> preorder[j];
		}
		for (int j=0; j<numNodes; j++) {
			cin >> inorder[j];
		}
		solve();
	}
}