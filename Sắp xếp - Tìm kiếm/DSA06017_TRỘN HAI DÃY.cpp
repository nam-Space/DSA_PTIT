#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int *a = new int[n];
		int *b = new int[m];
		multiset<int> res;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			res.insert(a[i]);
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			res.insert(b[i]);
		}
		for (int x : res) cout << x << " ";
		cout << endl;
	}
	return 0;
}

