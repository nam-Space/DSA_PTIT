#include <bits/stdc++.h> 
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int v = q.front();
		cout << v << " ";
		q.pop();
		for (int x : adj[v]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
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
			adj[y].push_back(x);
		}
		bfs(k);
		cout << endl;
		for (int i = 0; i < 1001; i++) {
			adj[i].clear();
		}
	}
	return 0;
}



