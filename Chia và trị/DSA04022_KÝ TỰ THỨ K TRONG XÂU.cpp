#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

char find(ll n, ll k) {
	if (n == 1) return 'A';
	if (k == pow(2, n - 1)) return n + 64;
	if (k > pow(2, n - 1)) return find(n - 1, pow(2, n - 1) - (k - pow(2, n - 1)));
	return find(n - 1, k);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	} 
	return 0;
}

