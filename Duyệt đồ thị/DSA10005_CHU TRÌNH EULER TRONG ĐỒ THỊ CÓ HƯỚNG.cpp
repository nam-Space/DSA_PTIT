#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];
int in[1001], out[1001];
bool visited[1001];

void nhap() {
	for (int i = 0; i < 1001; i++) {
		adj[i].clear();
	}
	memset(visited, false, sizeof(visited));
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		out[x]++;
		in[y]++;
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
		if (in[i] != out[i]) return false;
	}
	return true;
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
			cout << "1" << endl;
		}
		else cout << "0" << endl;
	}
}

