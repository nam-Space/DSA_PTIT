#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, s;
		cin >> n >> s;
		int a[n + 1];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int dp[s + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = s; j >= a[i]; j--) {
				if (dp[j - a[i]] == 1) dp[j] = 1;
			}
		}
		if (dp[s]) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
	return 0;
}

