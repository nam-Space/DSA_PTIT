#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

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
		ll n, r;
		cin >> n;
		string s = to_string(n);
		reverse(s.begin(), s.end());
		r = stoll(s);
		cout << Pow(n, r) << endl;
	} 
	return 0;
}

