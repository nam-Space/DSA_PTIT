#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct edge{
	int dau, cuoi;
};

int n, m;
int parent[1001], sz[1001];
bool visited[1001];
vector<edge> canh;

void nhap() {
	memset(parent, 0, sizeof(parent));
	memset(visited, false, sizeof(visited));
	canh.clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		canh.push_back({x, y});
	}
}

void make_set() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
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

bool chu_trinh() {
	for (edge x : canh) {
		int a = x.dau;
		int b = x.cuoi;
		if (!Union(a, b)) return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		make_set();
		if (chu_trinh()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
