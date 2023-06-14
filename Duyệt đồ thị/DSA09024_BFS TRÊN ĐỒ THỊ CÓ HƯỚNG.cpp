#include <bits/stdc++.h> 
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void bfs(int u) {
	queue<int> st;
	st.push(u);
	visited[u] = true;
	while(!st.empty()) {
		int top = st.front();
		st.pop();
		cout << top << " ";
		for (int x : adj[top]) {
			if (!visited[x]) {
				st.push(x);
				visited[x] = true;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		memset(visited, false, sizeof(visited));
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		bfs(k);
		cout << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}



