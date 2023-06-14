#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;

int a[100001];

int first_pos(int a[], int l, int r, int x) {
	int res = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			res = m;
			r = m - 1;
		}
		else if (a[m] < x) {
			l = m + 1;
		}
		else r = m - 1;
	}
	return res;
}

int last_pos(int a[], int l, int r, int x) {
	int res = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			res = m;
			l = m + 1;
		}
		else if (a[m] > x) {
			r = m - 1;
		}
		else l = m + 1;
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int l = first_pos(a, i + 1, n - 1, k - a[i]);
			int r = last_pos(a, i + 1, n - 1, k - a[i]);
			if (l != -1) {
				ans += r - l + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
