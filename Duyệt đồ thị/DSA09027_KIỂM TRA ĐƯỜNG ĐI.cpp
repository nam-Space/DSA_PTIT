#include <bits/stdc++.h>
using namespace std;

bool visited[1001];
vector<int> adj[1001];
int n, m;

void bfs(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		int v = q.front();
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
	cin>>t;
	while(t--){
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 1001; i++) {
			adj[i].clear();
		}
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int q;
		cin >> q;
		while(q--) {
			memset(visited, false, sizeof(visited));
			int s, t;
			cin >> s >> t;
			bfs(s);
			if (visited[t]) cout << "YES" << endl;
			else cout << "NO" << endl;
		} 
	}
	return 0;
}
