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

void insert(Node *root, int n1, int n2, char c) {
	if (root == NULL) return;
	if (root->data == n1) {
		if (c == 'L') root->left = new Node(n2);
		else root->right = new Node(n2);
	}
	else {
		insert(root->left, n1, n2, c);
		insert(root->right, n1, n2, c);
	}
}

void bfs(Node *root) {
	queue<Node*> q;
	q.push(root);
	cout << root->data << " ";
	while(!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node *tmp = q.front();
			q.pop();
			if (tmp->left != NULL) {
				q.push(tmp->left);
				cout << tmp->left->data << " ";
			}
			if (tmp->right != NULL) {
				q.push(tmp->right);
				cout << tmp->right->data << " ";
			}
		}
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node *root = NULL;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int n1, n2;
			char c;
			cin >> n1 >> n2 >> c;
			if (root == NULL) {
				root = new Node(n1);
				if (c == 'L') root->left = new Node(n2);
				else root->right = new Node(n2);
			}
			else insert(root, n1, n2, c);
		}
		bfs(root);
	}
}

