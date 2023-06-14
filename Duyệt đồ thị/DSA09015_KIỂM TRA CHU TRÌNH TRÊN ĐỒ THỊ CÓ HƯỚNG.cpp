#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001], color[1001], in[1001];

void nhap() {
	memset(in, 0, sizeof(in));
	for (int i = 0; i < 1001; i++) adj[i].clear();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		in[y]++;
	}
}

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) q.push(i);
	}
	int cnt = 0;
	while(!q.empty()) {
		int v = q.front(); q.pop();
		cnt++;
		for (int x : adj[v]) {
			in[x]--;
			if (in[x] == 0) {
				q.push(x);
			}
		}
	}
	return cnt == n;
}
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (bfs()) cout << "NO" << endl;
		else cout << "YES" << endl;
	} 
}


