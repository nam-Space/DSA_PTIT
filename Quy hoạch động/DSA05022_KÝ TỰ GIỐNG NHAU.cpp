#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	int insert, del, copy;
    	cin >> insert >> del >> copy;
    	int dp[n + 1];
    	memset(dp, 0, sizeof(dp));
    	dp[1] = insert;
    	for (int i = 2; i <= n; i++) {
    		if (i % 2 == 0) dp[i] = min(dp[i / 2] + copy, dp[i - 1] + insert);
    		else dp[i] = min(dp[(i + 1) / 2] + copy + del, dp[i - 1] + insert);
		}
		cout << dp[n] << endl;
	}
}


