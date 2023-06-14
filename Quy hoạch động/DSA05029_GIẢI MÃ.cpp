#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int dp[n + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = dp[1] = 1;
		if (s[0] == '0') {
			cout << "0" << endl;
			continue;
		} 
		for (int i = 2; i <= n; i++) {
			if (s[i - 1] > '0') dp[i] = dp[i - 1];
			if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
				dp[i] += dp[i - 2];
			}
		}
		cout << dp[n] << endl;
	} 
	return 0;
}

