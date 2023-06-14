#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
const int inf = 1e9;

int n, m;
int a[1001][1001], d[1001][1001], ne[1001][1001];

void nhap() {
	memset(d, 0, sizeof(d));
	memset(a, 0, sizeof(a));
	memset(ne, 0, sizeof(ne));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) a[i][j] = 0;
			else a[i][j] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		a[x][y] = w;
		a[y][x] = w; 
	}
}

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = a[i][j];
			ne[i][j] = j; 
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					ne[i][j] = ne[i][k];
				}
			}
		}
	}
}

int main() {
	int t;
	t = 1;
	while(t--) {
		nhap();
		floyd();
		int q;
		cin >> q;
		while(q--) {
			int x, y; cin >> x >> y;
			cout << d[x][y] << endl; 
		}
	}
}

