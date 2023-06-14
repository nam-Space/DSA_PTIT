#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		vector<int> lonNhat(n + 1, INT_MIN);
		for (int i = n - 1; i >= 0; i--) {
			lonNhat[i] = max(a[i], lonNhat[i + 1]);
		}
		int res = -1;
		for (int i = 0; i < n - 1; i++) {
			int l = i + 1;
			int r = n - 1;
			while(l <= r) {
				int m = (l + r) / 2;
				if (lonNhat[m] > a[i]) {
					l = m + 1;
					res = max(res, m - i);
				}
				else r = m - 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}

