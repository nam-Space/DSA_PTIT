#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m, res;
int a[1001][1001];
bool visited[1001][1001];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void nhap() {
	res = 0;
	memset(a, 0, sizeof(a));
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j];
	}
} 

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 2) {
				q.push({i, j});
				visited[i][j] = true;
			}
		}
	}
	while(!q.empty()) {
		int size = q.size();
		bool check = false;
		for (int i = 0; i < size; i++) {
			pair<int, int> top = q.front();
			q.pop();
			int x = top.first;
			int y = top.second;
			for (int k = 0; k < 4; k++) {
				int i1 = x + dx[k];
				int j1 = y + dy[k];
				if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1 && !visited[i1][j1]) {
					a[i1][j1] = 2;
					visited[i1][j1] = true;
					q.push({i1, j1});
					check = true;
				}
			}
		}
		if (check) res++;
	}
}

int soNgay() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == 1) return -1;
		}
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		bfs();
		cout << soNgay() << endl;
	}
}

