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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
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
			} 
		}
	}
}

bool strong_connected() {
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		bfs(i);
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (strong_connected()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
