#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int s, t, cnt;
int prime[10000], nto[10000];
vector<int> adj[10000];
bool visited[10000];

void sang() {
	for (int i = 0; i < 10000; i++) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i < 100; i++) {
		if (prime[i]) {
			for (int j = i * i; j < 10000; j += i) {
				prime[j] = 0;
			}
		}
	}
	cnt = 1;
	for (int i = 1000; i < 10000; i++) {
		if (prime[i]) {
			nto[cnt++] = i;
		}
	}
}

bool check_1_digit(int a, int b) {
	string s1 = to_string(a);
	string s2 = to_string(b);
	int dem = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i]) dem++;
	}
	return dem == 1;
}

void init() {
	for (int i = 1; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			if (check_1_digit(nto[i], nto[j])) {
				adj[nto[i]].push_back(nto[j]);
				adj[nto[j]].push_back(nto[i]);
			}
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	q.push({s, 0});
	while(!q.empty()) {
		pair<int, int> v = q.front(); q.pop();
		if (v.first == t) return v.second;
		for (int x : adj[v.first]) {
			if (!visited[x]) {
				q.push({x, v.second + 1});
				visited[x] = true;
			}
		}
	}
	return 0;
}

int main(){
	sang();
	init();
    int test;
    cin >> test;
    while(test--) {
    	memset(visited, false, sizeof(visited));
    	cin >> s >> t;
    	cout << bfs() << endl;
	}
	return 0;
}