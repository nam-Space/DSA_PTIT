#include <bits/stdc++.h>
using namespace std;

int n, m, res;
bool visited[1001][1001];
vector<int> adj[1001];

void nhap() {
	res = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) {
		adj[i].clear();
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int u, int cnt) {
	res = max(res, cnt);
	for (int x : adj[u]) {
		if (!visited[u][x]) {
			visited[u][x] = visited[x][u] = true;
			dfs(x, cnt + 1);
			visited[u][x] = visited[x][u] = false;
		}
	}
}

int main(){
	int test; 
	cin >> test;
	while(test--){
		nhap();
		for (int i = 0; i <= n - 1; i++) {
			memset(visited, false, sizeof(visited));
			dfs(i, 0);
		}
		cout << res << endl;
	}
	return 0;
}




