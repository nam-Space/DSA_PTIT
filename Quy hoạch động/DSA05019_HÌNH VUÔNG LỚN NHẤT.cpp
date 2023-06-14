#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	int a[n + 1][m + 1], dp[n + 1][m + 1];
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= m; j++) {
    			cin >> a[i][j];
    			dp[i][j] = a[i][j];
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j - 1]) {
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					res = max(res, dp[i][j]);
				}
			}
		}
		cout << res << endl;
	}
}


