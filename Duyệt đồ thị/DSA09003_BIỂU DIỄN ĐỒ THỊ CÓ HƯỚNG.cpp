#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];

int main(){
    int t; 
	cin >> t;
    while(t--){
    	for(int i = 0; i < 1001; i++) {
    		adj[i].clear();
		}
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			cout << i << ": ";
			for (int x : adj[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
    }
}
