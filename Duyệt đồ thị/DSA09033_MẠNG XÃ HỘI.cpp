#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[100001];
bool visited[100001];

void nhap() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 100001; i++) adj[i].clear();
	cin >> n >> m;
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
			dfs(x);
		}
	}
}

int connectedComponent() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (connectedComponent() == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
}



