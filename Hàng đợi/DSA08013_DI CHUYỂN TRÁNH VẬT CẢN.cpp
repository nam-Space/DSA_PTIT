#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
char s[1001][1001];
bool visited[1001][1001];
int res;

struct Data {
	int x, y, cnt;
};

void nhap() {
	res = 1e9;
	memset(visited, false, sizeof(visited));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	cin >> a >> b >> c >> d;
}

void bfs() {
	queue<Data> q;
	q.push({a, b, 0});
	visited[a][b] = true;
	while(!q.empty()) {
		Data v = q.front(); q.pop();
		if (v.x == c && v.y == d) res = min(res, v.cnt);
		for (int k = v.x + 1; k < n; k++) {
			if (!visited[k][v.y] && s[k][v.y] == '.') {
				q.push({k, v.y, v.cnt + 1});
				visited[k][v.y] = true;
			}
			else break;
		}
		for (int k = v.x - 1; k >= 0; k--) {
			if (!visited[k][v.y] && s[k][v.y] == '.') {
				q.push({k, v.y, v.cnt + 1});
				visited[k][v.y] = true;
			}
			else break;
		}
		for (int k = v.y + 1; k < n; k++) {
			if (!visited[v.x][k] && s[v.x][k] == '.') {
				q.push({v.x, k, v.cnt + 1});
				visited[v.x][k] = true;
			}
			else break;
		}
		for (int k = v.y - 1; k >= 0; k--) {
			if (!visited[v.x][k] && s[v.x][k] == '.') {
				q.push({v.x, k, v.cnt + 1});
				visited[v.x][k] = true;
			}
			else break;
		}
	}
}


int main(){
	int t; 
	cin >> t;
	while(t--){
		nhap();
		bfs();
		cout << res << endl;
	}
	return 0;
}




