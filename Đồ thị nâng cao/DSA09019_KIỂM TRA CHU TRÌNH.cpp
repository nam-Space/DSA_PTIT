#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void nhap() {
	memset(parent, 0, sizeof(parent));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

bool dfs(int u) {
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x]) {
			parent[x] = u;
			if (dfs(x)) return true;
		}
		else if (x != parent[u]) return true;
	}
	return false;
}

bool chu_trinh() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(i)) return true;
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


