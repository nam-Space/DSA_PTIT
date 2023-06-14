#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];
int degree[1001];
bool visited[1001];

void nhap() {
	for (int i = 0; i < 1001; i++) {
		adj[i].clear();
	}
	memset(visited, false, sizeof(visited));
	memset(degree, 0, sizeof(degree));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
}

void dfs(int u) {
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x]) dfs(x);
	}
}

bool connectedComponent() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	return cnt == 1;
}

bool eulerCycle() {
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (degree[i] % 2 == 1) return false;
	}
	return true;
}

bool eulerPath() {
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (degree[i] % 2 == 1) cnt++;
	}
	return cnt == 2;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
    	nhap();
    	if (!connectedComponent()) {
    		cout << "0" << endl;
    		continue;
		}
		if (eulerCycle()) {
			cout << "2" << endl;
		}
		else {
			if (eulerPath()) cout << "1" << endl;
			else cout << "0" << endl;
		}
	}
}

