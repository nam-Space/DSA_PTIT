#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

int n, m;
vector<int> adj[1001];
int a[1001][1001];
bool visited[1001];

void nhap() {
	memset(a, 0, sizeof(a));
	for(int i = 0; i < 1001; i++) {
    	adj[i].clear();
	}
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp) {
			int x = stoi(tmp);
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
	}
}

int main(){
    int t; 
	t = 1;
    while(t--){
    	nhap();
    	for (int i = 1; i <= n; i++) {
    		for (int x : adj[i]) {
    			a[i][x] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
    }
}
