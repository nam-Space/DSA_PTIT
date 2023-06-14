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
    	ll a[n], b[n];
    	for (ll &x : a) cin >> x;
    	for (ll &x : b) cin >> x;
    	sort(a, a + n);
    	sort(b, b + n, greater<ll>());
    	ll ans = 0;
    	for (int i = 0; i < n; i++) {
    		ans += a[i] * b[i];
		}
		cout << ans << endl;
	}
}


