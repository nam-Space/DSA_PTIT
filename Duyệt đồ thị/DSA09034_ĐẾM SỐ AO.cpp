#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
bool visited[1001][1001];
char a[1001][1001];

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
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'W' && !visited[i1][j1]) {
			dfs(i1, j1);
		}
	}
}

int connectedComponent() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'W' && !visited[i][j]) {
				cnt++;
				dfs(i, j);
			}
		}
	}
	return cnt;
}

int main() {
	int t;
	t = 1;
	while(t--) {
		nhap();
		cout << connectedComponent() << endl;
	}
}

