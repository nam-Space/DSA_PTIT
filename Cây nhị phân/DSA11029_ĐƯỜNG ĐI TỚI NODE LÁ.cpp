#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
vector<vector<int>> res;

void nhap() {
	res.clear();
	memset(parent, 0, sizeof(parent));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) {
		adj[i].clear();
	}
	cin >> n;
	m = n - 1;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}

void dfs(int u) {
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x]) {
			parent[x] = u;
			dfs(x);
		}
	}
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		nhap();
		dfs(1);
		for (int i = 1; i <= n; i++) {
			if (adj[i].size() == 0) {
				vector<int> v;
				int en = i;
				int st = 1;
				while(en != st) {
					v.push_back(en);
					en = parent[en];
				}
				v.push_back(en);
				reverse(v.begin(), v.end());
				res.push_back(v);
			}
		}
		for (vector<int> v : res) {
			for (int x : v) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}


