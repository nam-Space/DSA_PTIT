#include <bits/stdc++.h>
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
    	int dp[n + 1][n + 1];
    	memset(dp, 0, sizeof(dp));
    	for (int i = 1; i <= n; i++) {
    		dp[i][i] = 1;
		}
		int res = 0;
		for (int len = 2; len <= n; len++) {
			for (int i = 1; i <= n - len + 1; i++) {
				int j = i + len - 1;
				if (len == 2 && s[i - 1] == s[j - 1]) dp[i][j] = 1;
				else dp[i][j] = dp[i + 1][j - 1] && s[i - 1] == s[j - 1];
				if (dp[i][j]) res = max(res, len);
			}
		}
		cout << res << endl;
	}
}


