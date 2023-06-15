#include <bits/stdc++.h>
using namespace std;

int n, m, res;
vector<int> adj[1000001];
bool visited[1000001];

void nhap() {
	res = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1000001; i++) {
		adj[i].clear();
	}
	cin >> n;
	m = n - 1;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}

void bfs(int u) {
	queue<pair<int, int>> q;
	q.push({u, 0});
	visited[u] = true;
	while(!q.empty()) {
		pair<int, int> top = q.front(); q.pop();
		res = max(res, top.second);
		for (int x : adj[top.first]) {
			if (!visited[x]) {
				q.push({x, top.second + 1});
				visited[top.first] = true;
			}
		}
	}
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		nhap();
		bfs(1);
		cout << res << endl;
	}
	return 0;
}


