#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct edge {
	int dau, cuoi, w;
};

int n, m, s;
vector<pair<int, int>> adj[1001];
int parent[1001], sz[1001];
bool visited[1001];
vector<edge> canh;

void nhap() {
	canh.clear();
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < 1001; i++) {
		adj[i].clear();
	}
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		canh.push_back({x, y, w});
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}

void dijkstra(int s) {
	vector<int> d(n + 1, INT_MAX);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while(!pq.empty()) {
		pair<int, int> top = pq.top(); pq.pop();
		int u = top.second;
		int kc = top.first;
		if (kc > d[u]) continue;
		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << d[i] << " ";
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		dijkstra(s);
	}
	return 0;
}



