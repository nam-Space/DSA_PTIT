#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k;

ll Pow(int k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	ll tmp = Pow(k / 2);
	if (k % 2 == 1) return tmp * tmp % mod * n % mod;
	return tmp * tmp % mod;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << Pow(k) << endl;
	} 
	return 0;
}

