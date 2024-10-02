#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

bool check(vector<ll> dp, ll k) {
	if (k == 0) return false;
	int n = dp.size();
	multiset<ll> se;
	for (int i = 1; i <= n; i++) {
		se.insert(dp[i]);
	}
	for (int i = 0; i <= n; i++) {
		if (se.count(dp[i] + k) != 0) return true;
	}
	return false;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		int a[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<ll> dp(n + 1, 0);
		for (int i = 1; i <= n; i++) dp[i] = a[i];
		for (int i = 1; i <= n; i++) {
			dp[i] += dp[i - 1];
		}
		if (check(dp, k)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
