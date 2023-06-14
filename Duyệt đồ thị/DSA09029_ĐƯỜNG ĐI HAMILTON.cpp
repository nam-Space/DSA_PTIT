#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
const int inf = 1e9;

int n, m, v0;
int x[1001];
vector<int> adj[1001];
bool visited[1001];

void nhap() {
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) x[i] = i;
}

bool Hamilton(int k) {
	for (int y : adj[x[k - 1]]) {
		if (k == n + 1) return true;
		else if (!visited[y]) {
			x[k] = y;
			visited[y] = true;
			if (Hamilton(k + 1)) return true;
			visited[y] = false;
		}
	}
	return false;
}

bool hamlton_cycle() {
	for (int i = 1; i <= n; i++) {
		v0 = i;
		x[1] = v0;
		visited[v0] = true;
		if (Hamilton(2)) return true;
		memset(visited, false, sizeof(visited));
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (hamlton_cycle()) cout << "1" << endl;
		else cout << "0" << endl;
	}
}

