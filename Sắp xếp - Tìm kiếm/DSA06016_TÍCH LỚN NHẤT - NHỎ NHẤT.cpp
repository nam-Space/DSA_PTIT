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
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		cout << 1ll * (*max_element(a, a + n)) * (*min_element(b, b + m)) << endl;
	}
	return 0;
}

