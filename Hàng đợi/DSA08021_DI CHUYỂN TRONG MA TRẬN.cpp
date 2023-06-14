#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct Data {
	int first, second, third;
};

int n, m, res;
int a[1001][1001];
bool visited[1001][1001];

void bfs() {
	queue<Data> q;
	q.push({1, 1, 0});
	while(!q.empty()) {
		Data v = q.front(); q.pop();
		if (v.first == m && v.second == n) res = min(res, v.third);
		int i1 = v.first;
		int j1 = v.second + a[v.first][v.second];
		if (i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && !visited[i1][j1]) {
			q.push({i1, j1, v.third + 1});
			visited[i1][j1] = true;
		}
		int i2 = v.first + a[v.first][v.second];
		int j2 = v.second;
		if (i2 >= 1 && i2 <= m && j2 >= 1 && j2 <= n && !visited[i2][j2]) {
			q.push({i2, j2, v.third + 1});
			visited[i2][j2] = true;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		res = 1e9;
		memset(visited, false, sizeof(visited));
		cin >> m >> n;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		bfs();
		if (res == 1e9) cout << "-1" << endl;
		else cout << res << endl;
	}
}

