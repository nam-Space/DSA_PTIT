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
		adj[y].push_back(x);
	}
}

int bfs(int u, int v) {
	queue<pair<int, int>> q;
	q.push({u, 0});
	visited[u] = true;
	while(!q.empty()) {
		pair<int, int> top = q.front(); q.pop();
		if (top.first == v) return top.second;
		for (int x : adj[top.first]) {
			if (!visited[x]) {
				q.push({x, top.second + 1});
				visited[x] = true;
			}
		}
	}
	return 0;
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		nhap();
		int q;
		cin >> q;
		while(q--) {
			memset(visited, false, sizeof(visited));
			int u, v;
			cin >> u >> v;
			cout << bfs(u, v) << endl;
		}
	}
	return 0;
}



