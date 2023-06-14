#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, v;
		cin >> n >> v;
		int a[n + 1], c[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> c[i];
		}
		int dp[n + 1][v + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= v; j++) {
				if (i == 0 || j == 0) dp[i][j] = 0;
				else {
					dp[i][j] = dp[i - 1][j];
					if (j >= a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + c[i]);
				}
			}
		}
		cout << dp[n][v] << endl;
	} 
	return 0;
}

