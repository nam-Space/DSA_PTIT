#include <bits/stdc++.h> 
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int u) {
	cout << u << " ";
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x]) {
			dfs(x);
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		memset(visited, false, sizeof(visited));
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		dfs(k);
		cout << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}



