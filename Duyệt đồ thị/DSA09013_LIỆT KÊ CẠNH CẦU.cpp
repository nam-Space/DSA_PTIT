#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct edge {
	int dau, cuoi;
};

int n, m;
vector<int> adj[1001];
bool visited[1001];
vector<edge> canh;

void nhap() {
	canh.clear();
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) {
		adj[i].clear();
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		canh.push_back({x, y});
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

void dfs2(int u, int s, int t) {
	visited[u] = true;
	for (int x : adj[u]) {
		if (!visited[x] && !((s == u && t == x) || (s == x && t == u))) {
			dfs2(x, s, t);
		}
	}
}

void canh_cau() {
	int cntRoot = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cntRoot++;
			dfs(i);
		}
	}
	for (int i = 0; i < m; i++) {
		edge e = canh[i];
		int s = e.dau, t = e.cuoi;
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				cnt++;
				dfs2(j, s, t);
			}
		}
		if (cntRoot < cnt) {
			cout << s << " " << t << " ";
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		canh_cau();
		cout << endl;
	}
	return 0;
}



