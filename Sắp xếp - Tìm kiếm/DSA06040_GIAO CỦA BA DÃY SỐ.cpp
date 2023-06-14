#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void merge(int a[], int l, int m, int r) {
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < x.size() && j < y.size()) {
		if (x[i] < y[j]) a[l++] = x[i++];
		else a[l++] = y[j++];
	}
	while(i < x.size()) a[l++] = x[i++];
	while(j < y.size()) a[l++] = y[j++];
}

void merge_sort(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		ll a[n], b[m], c[k];
		for (ll &x : a) cin >> x;
		for (ll &x : b) cin >> x;
		for (ll &x : c) cin >> x;
		vector<ll> res;
		int i = 0, j = 0, z = 0;
		while(i < n && j < m && z < k) {
			if (a[i] == b[j] && a[i] == c[z]) {
				res.push_back(a[i]);
				i++;
				j++;
				z++;
			}
			else if (a[i] <= b[j] && a[i] <= c[z]) i++;
			else if (b[j] <= a[i] && b[j] <= c[z]) j++;
			else z++;
		}
		if (res.size() == 0) cout << "-1" << endl;
		else {
			sort(res.begin(), res.end());
			for (ll x : res) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}

