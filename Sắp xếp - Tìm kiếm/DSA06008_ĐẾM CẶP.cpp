#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int cnt[5];

int first_pos(int a[], int l, int r, int x) {
	int pos = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] > x) {
			r = m - 1;
			pos = m;
		}
		else l = m + 1;
	}
	return pos;
}

int dem_cap(int x, int b[], int m) {
	if (x == 0) return 0;
	if (x == 1) return cnt[0];
	int res = cnt[0] + cnt[1];
	int pos = first_pos(b, 0, m - 1, x);
	if (pos != -1) {
		res += m - pos;
		if (x == 2) res -= (cnt[3] + cnt[4]);
		if (x == 3) res += cnt[2];
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof(cnt));
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) 
		{
			cin >> b[i];
			if (b[i] <= 4) cnt[b[i]]++;
		}
		sort(b, b + n);
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += dem_cap(a[i], b, m);
		}
		cout << res << endl;
	}
	return 0;
}

