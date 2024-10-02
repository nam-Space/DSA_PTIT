#include<bits/stdc++.h>
using namespace std;

struct Data {
	int x, y, cnt;
};

int n, m;
int a[1001][1001], visited[1001][1001];

int bfs(int i, int j, int a[1001][1001]) {
	queue<Data> q;
	q.push({i, j, 0});
	visited[i][j] = 1;
	while(!q.empty()) {
		Data tmp = q.front(); q.pop();
		if (tmp.x == n && tmp.y == m && visited[tmp.x][tmp.y]) return tmp.cnt;
		int x1 = tmp.x + abs(a[tmp.x + 1][tmp.y] - a[tmp.x][tmp.y]);
		int y1 = tmp.y;
		if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !visited[x1][y1]){
			q.push({x1, y1, tmp.cnt + 1});
			visited[x1][y1] = 1;
		}
		
		int x2 = tmp.x;
		int y2 = tmp.y + abs(a[tmp.x][tmp.y + 1] - a[tmp.x][tmp.y]);
		if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && !visited[x2][y2]) {
			q.push({x2, y2, tmp.cnt + 1});
			visited[x2][y2] = 1;
		}
		
		int x3 = tmp.x + abs(a[tmp.x + 1][tmp.y + 1] - a[tmp.x][tmp.y]);
		int y3 = tmp.y + abs(a[tmp.x + 1][tmp.y + 1] - a[tmp.x][tmp.y]);
		if (x3 >= 1 && x3 <= n && y3 >= 1 && y3 <= m && !visited[x3][y3]) {
			q.push({x3, y3, tmp.cnt + 1});
			visited[x3][y3] = 1;
		}
	}
	return -1;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		memset(visited, 0, sizeof(visited));
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		cout << bfs(1, 1, a) << endl;
	}
	return 0;
}