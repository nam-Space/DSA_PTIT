#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 123456789;

ll Pow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n % mod;
	ll tmp = Pow(n, k / 2);
	if (k % 2 == 1) return tmp * tmp % mod * n % mod;
	return tmp * tmp % mod;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << Pow(2, n - 1) << endl;
	} 
	return 0;
}

