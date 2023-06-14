#include <bits/stdc++.h> 
using namespace std;

vector<int> adj[1001];

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				adj[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int x : adj[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}



