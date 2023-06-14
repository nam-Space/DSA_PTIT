#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll Pow(ll n, ll k) {
	if (k == 0) return 1;
	if (k == 1) return n % mod;
	ll tmp = Pow(n, k / 2);
	if (k % 2 == 0) return tmp * tmp % mod;
	return tmp * tmp % mod * n % mod;
}

int main(){
	ll a, b;
	while(cin >> a >> b) {
		if (a == 0 && b == 0) break;
		cout << Pow(a, b) << endl;
	}
	return 0;
}

