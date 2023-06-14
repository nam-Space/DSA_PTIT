#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll dp[1001][1001];

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (j == 0 || i == j) dp[i][j] = 1;
				else {
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
					dp[i][j] %= mod;
				} 
			}
		}
		cout << dp[n][k] << endl;
	} 
	return 0;
}

