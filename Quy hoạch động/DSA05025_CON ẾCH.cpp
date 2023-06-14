#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		k = 3;
		cin >> n;
		ll dp[n + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= min(k, i); j++) {
				dp[i] += dp[i - j];
			}
		}
		cout << dp[n] << endl;
	} 
	return 0;
}

