// Retrospection(about mistake): I was confused about merge function's recurisve invariant. 
// I called the function like this: merge(n2->left, n1). But n1 < n2->left.
#include<iostream>
#include<vector>
#include<set>
#include<cstdlib>
#include<cassert>
using namespace std;

struct Node {
	int size, priority, val;
	Node*left;
	Node*right;
	Node(int _val):val(_val), priority(rand()), size(1), left(NULL), right(NULL){}
	void setLeft(Node*n) {
		left = n;
		calcSize();
	}
	void setRight(Node*n) {
		right = n;
		calcSize();
	}
	void calcSize() {
		size = 1;
		if (left) size+=left->size;
		if (right) size+=right->size;
	}
};

// split with val
pair<Node*,Node*> split(Node* root, int val) {
	if (root == NULL) return pair<Node*, Node*>(NULL, NULL);
	if (root->val<val) {
		pair<Node*,Node*> splitted = split(root->right, val);
		root->setRight(splitted.first);
		return pair<Node*,Node*>(root, splitted.second);
	} else {
		pair<Node*,Node*> splitted = split(root->left, val);
		root->setLeft(splitted.second);
		return pair<Node*,Node*>(splitted.first, root);
	}
}

Node* insert(Node* root, Node* n) {
	if (root == NULL) return n;
	if (root->val == n->val) {
		return root;
	}
	if (root->priority < n->priority) {
		pair<Node*,Node*> splited = split(root, n->val);
		n->setLeft(splited.first);
		n->setRight(splited.second);
		return n;
	} else if (root->val < n->val) {
		root->setRight(insert(root->right, n));
	} else {
		root->setLeft(insert(root->left, n));
	}
	return root;
}

// max(n1) < min(n2)
Node* merge(Node*n1, Node*n2) {
	if (n1 == NULL) return n2;
	if (n2 == NULL) return n1;
	if (n1->priority < n2->priority) {
		n2->setLeft(merge(n1, n2->left));
		return n2;
	} else {
		n1->setRight(merge(n1->right, n2));
		return n1;
	}
}

Node* erase(Node* root, int val) {
	if (root == NULL) return NULL;
	if (root->val == val) {
		return merge(root->left, root->right);
	}
	if (val < root->val) {
		root->setLeft(erase(root->left, val));
	} else {
		root->setRight(erase(root->right, val));
	}
	return root;
}

int kth(Node*root, int k) {
	assert(root!=NULL);
	int leftSize = 0;
	if (root->left!=NULL) leftSize = root->left->size;
	if (k<=leftSize)
		return kth(root->left, k);
	if (k==leftSize+1) {
		return root->val;
	} else {
		return kth(root->right, k-leftSize-1);
	}
}

int len;

void solve(vector<int>& v) {
	vector<int> origin(len);
	Node* tree = new Node(1);
	for (int i=2; i<=len; i++) {
		tree=insert(tree, new Node(i));
	}
	for (int i=len-1; 0<=i; i--) {
		origin[i] = kth(tree, i-v[i]+1);
		tree=erase(tree, origin[i]);
	}
	for (int i=0; i<len; i++) {
		cout << origin[i];
		if (i+1!=len)
			cout << " ";
	}
	cout <<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> len;
		vector<int> v(len, 0);
		for (int j=0; j<len; j++) {
			cin >> v[j];
		}
		solve(v);
	}
}
