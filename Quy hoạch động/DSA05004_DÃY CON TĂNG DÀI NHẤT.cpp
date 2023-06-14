#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	t = 1;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<int> dp(n + 1, 1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << endl;
	} 
	return 0;
}

