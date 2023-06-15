#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];
bool visited[1001][1001];
string res;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct Data {
	int x, y, cnt;
	char direction;
};

void nhap() {
	res = "NO";
	memset(visited, false, sizeof(visited));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}

char makeDirection(int i, int j) {
	if (i == -1 && j == 0) return 'U';
	if (i == 0 && j == -1) return 'L';
	if (i == 0 && j == 1) return 'R';
	return 'D';
}

void bfs(int s, int t) {
	queue<Data> q;
	q.push({s, t, 0, 'O'});
	visited[s][t] = true;
	while(!q.empty()) {
		Data v = q.front(); q.pop();
		if (v.cnt <= 3 && a[v.x][v.y] == 'T') {
			res = "YES";
			return;
		}
		if (v.cnt > 3) continue;
		for (int i = 0; i < 4; i++) {
			int i1 = v.x + dx[i];
			int j1 = v.y + dy[i];
			int direct = makeDirection(dx[i], dy[i]);
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]) {
				if (a[i1][j1] != '*') {
					if (v.direction != direct) {
						q.push({i1, j1, v.cnt + 1, direct});
						visited[i1][j1] = true;
					}
					else {
						q.push({i1, j1, v.cnt, direct});
						visited[i1][j1] = true;
					}
				}
			}
		}
	}
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		nhap();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 'S') {
					bfs(i, j);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}



