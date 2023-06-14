#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct edge {
	int dau, cuoi;
};

int n, m, goc;
bool visited[1001];
vector<int> adj[1001];
vector<edge> canh;

void nhap() {
	canh.clear();
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m >> goc;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int u) {
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x]) {
			canh.push_back({u, x});
			dfs(x);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		dfs(goc);
		if (canh.size() < n - 1) cout << "-1" << endl;
		else {
			for (edge x : canh) cout << x.dau << " " << x.cuoi << endl;
		}
	}
	return 0;
}
