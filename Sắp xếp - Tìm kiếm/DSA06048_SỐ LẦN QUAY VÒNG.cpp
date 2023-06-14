#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

bool check(ll a[], ll b[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a + n);
		int k = 0;
		while(!check(a, b, n)) {
			k++;
			ll tmp = b[0];
			for (int i = 0; i < n - 1; i++) {
				b[i] = b[i + 1];
			}
			b[n - 1] = tmp;
		}
		cout << k << endl;
	}
	return 0;
}

