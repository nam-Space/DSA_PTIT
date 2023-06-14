#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll merge(ll a[], int l, int m, int r) {
	ll cnt = 0;
	vector<ll> x(a + l, a + m + 1);
	vector<ll> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < x.size() && j < y.size()) {
		if (x[i] <= y[j]) {
			a[l++] = x[i++];
		}
		else {
			a[l++] = y[j++];
			cnt += x.size() - i;
		}
	}
	while(i < x.size()) {
		a[l++] = x[i++];
	}
	while(j < y.size()) {
		a[l++] = y[j++];
	}
	return cnt;
}

ll merge_sort(ll a[], int l, int r) {
	ll cnt = 0;
	if (l < r) {
		int m = (l + r) / 2;
		cnt += merge_sort(a, l, m);
		cnt += merge_sort(a, m + 1, r);
		cnt += merge(a, l, m, r);
	}
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll a[n];
		for (ll &x : a) cin >> x;
		cout << merge_sort(a, 0, n - 1) << endl;
	}
	return 0;
}

