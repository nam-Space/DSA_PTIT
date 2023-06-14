#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct edge {
	int dau, cuoi, w;
};

int n, m;
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		canh.push_back({x, y, w});
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
}

void make_set() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

void kruskal() {
	vector<edge> mst;
	int d = 0;
	sort(canh.begin(), canh.end(), cmp);
	for (int i = 0; i < m; i++) {
		edge e = canh[i];
		int a = e.dau, b = e.cuoi, trongSo = e.w;
		if (Union(a, b)) {
			mst.push_back({a, b, trongSo});
			d += trongSo;
		}
	}	
	cout << d << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		make_set();
		kruskal();
	}
	return 0;
}



