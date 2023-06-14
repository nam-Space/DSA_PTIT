#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll dp[1000001];

int main(){
	int t;
	cin >> t;
	while(t--) {
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		dp[0] = dp[1] = 0;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
			if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		cout << dp[n] << endl;
	}
	return 0;
}



