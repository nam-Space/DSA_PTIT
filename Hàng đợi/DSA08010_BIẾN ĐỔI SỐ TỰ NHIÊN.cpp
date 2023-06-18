#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int bfs(int u) {
	set<int> se;
	se.insert(u);
	queue<pair<int, int>> q;
	q.push({u, 0});
	while(!q.empty()) {
		pair<int, int> v = q.front(); q.pop();
		if (v.first == 1) return v.second;
		if (se.find(v.first - 1) == se.end() && v.first > 1) {
			q.push({v.first - 1, v.second + 1});
			se.insert(v.first - 1);
		}
		for (int i = 2; i <= sqrt(v.first); i++) {
			if (v.first % i == 0 && se.find(v.first / i) == se.end()) {
				q.push({v.first / i, v.second + 1});
				se.insert(v.first / i);
			}
		}
	}
	return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	cout << bfs(n) << endl;
	}
	return 0;
}