#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m, st, en;
bool visited[1001];
int parent[1001];
vector<int> adj[1001];

void nhap() {
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	st = 1, en = 0;
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
}

bool dfs(int u) {
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x]) {
			parent[x] = u;
			if (dfs(x)) return true;
		}
		else if (x != parent[u] && x == 1) {
			en = u;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (!dfs(1)) {
			cout << "NO" << endl;
			continue;
		}
		vector<int> res;
		res.push_back(st);
		while(st != en) {
			res.push_back(en);
			en = parent[en];
		}
		res.push_back(en);
		reverse(res.begin(), res.end());
		for (int x : res) cout << x << " ";
		cout << endl;
	} 
}



