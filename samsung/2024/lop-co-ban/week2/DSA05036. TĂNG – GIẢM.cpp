#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		float a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		vector<int> dp(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j] && b[i] < b[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
	return 0;
}