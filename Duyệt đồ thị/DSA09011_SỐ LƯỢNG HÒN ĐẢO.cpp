#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
using ll = long long;

int n, m;
int a[1001][1001];
bool visited[1001][1001];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void nhap() {
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}

void dfs(int i, int j) {
	visited[i][j] = true;
	for (int k = 0; k < 8; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1]) dfs(i1, j1);
	}
}

int countIsland() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && !visited[i][j]) {
				cnt++;
				dfs(i, j);
			} 
		}
	}
	return cnt;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		cout << countIsland() << endl;
	}
}
