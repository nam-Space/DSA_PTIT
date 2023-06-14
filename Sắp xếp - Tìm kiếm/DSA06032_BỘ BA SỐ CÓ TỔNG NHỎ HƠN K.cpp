#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		ll a[n];
		for (ll &x : a) cin >> x;
		sort(a, a + n);
		ll cnt = 0;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				cnt += lower_bound(a + j + 1, a + n, k - a[i] - a[j]) - a - 1 - j;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

