#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		ll res = 1;
		for (int i = 0; i <= k - 1; i++) {
			res *= n - i;
			res %= mod;
		}
		cout << res << endl;
	} 
	return 0;
}

