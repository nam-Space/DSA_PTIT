#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct Node {
	int data;
	Node *left, *right;
	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

void insert(Node *root, int x) {
	if (x < root->data) {
		if (root->left == NULL) root->left = new Node(x);
		else insert(root->left, x);
	}
	else {
		if (root->right == NULL) root->right = new Node(x);
		else insert(root->right, x);
	}
}

int height(Node* root) {
	if (root == NULL) return -1;
	return max(height(root->left), height(root->right)) + 1;
}

int main(){
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
		cout << height(root) << endl;
	} 
	return 0;
}



