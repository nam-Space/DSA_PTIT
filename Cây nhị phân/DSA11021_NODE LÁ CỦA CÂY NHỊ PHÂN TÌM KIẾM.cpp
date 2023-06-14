#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

void insert(Node *root, int x) {
	if (root->data > x) {
		if (root->left == NULL) root->left = new Node(x);
		else insert(root->left, x);
	}
	else {
		if (root->right == NULL) root->right = new Node(x);
		else insert(root->right, x);
	}
}

void preOrder(Node *root) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node *root = NULL;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (root == NULL) root = new Node(x);
			else insert(root, x);
		}
		preOrder(root);
		cout << endl;
	} 
}

