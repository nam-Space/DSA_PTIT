#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
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
		adj[y].push_back(x);
	}
}

bool bfs(int u) {
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
			else if (x != parent[v]) return true;
		}
	}
	return false;
}

bool chu_trinh() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (bfs(i)) return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (chu_trinh()) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
}


