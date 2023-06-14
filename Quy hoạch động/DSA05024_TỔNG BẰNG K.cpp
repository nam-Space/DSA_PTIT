#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	int a[n];
    	for (int &x : a) cin >> x;
    	int dp[k + 1];
    	memset(dp, 0, sizeof(dp));
    	dp[0] = 1;
    	for (int i = 1; i <= k; i++) {
    		for (int j = 0; j < n; j++) {
    			if (i >= a[j]) {
    				dp[i] += dp[i - a[j]];
    				dp[i] %= mod;
				}
			}
		}
		cout << dp[k] << endl;
	}
}


