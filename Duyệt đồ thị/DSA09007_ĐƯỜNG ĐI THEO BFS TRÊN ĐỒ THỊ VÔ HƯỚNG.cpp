#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
using ll = long long;

int n, m, s, en;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void nhap() {
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m >> s >> en;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			} 
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		bfs(s);
		vector<int> path;
		path.push_back(en);
		while(en != s) {
			en = parent[en];
			path.push_back(en);
		}
		reverse(path.begin(), path.end());
		for (int x : path) cout << x << " ";
		cout << endl;
	}
}
