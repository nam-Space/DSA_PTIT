#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001], color[1001];

void nhap() {
	memset(color, 0, sizeof(color));
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}

bool dfs(int u) {
	color[u] = 1;
	for (int x : adj[u]) {
		if (color[x] == 0) {
			if (dfs(x)) return true;
		}
		else if (color[x] == 1) return true;
	}
	color[u] = 2;
	return false;
}

bool chu_trinh() {
	for (int i = 1; i <= n; i++) {
		if (color[i] == 0) {
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


