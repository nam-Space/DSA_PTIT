#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int last_post(ll a[], int n, ll x) {
	int l = 0, r = n - 1;
	int pos = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] <= x) {
			pos = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return pos;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		ll a[n];
		for (ll &x : a) cin >> x;
		if (last_post(a, n, k) != -1) cout << last_post(a, n, k) + 1 << endl;
		else cout << "-1" << endl;
	} 
	return 0;
}

