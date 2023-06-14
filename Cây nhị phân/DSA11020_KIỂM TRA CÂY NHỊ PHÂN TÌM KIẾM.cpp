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

int main() {
	int t;
	cin >> t;
	while(t--) {
		Node *root = NULL;
		int n;
		cin >> n;
		int a[n];
		set<int> se;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			se.insert(a[i]);
		}
		bool ok = true;
		int cnt = 0;
		for (int x : se) {
			if (a[cnt++] != x) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "1" << endl;
		else cout << "0" << endl;
	} 
}

