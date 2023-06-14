#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 123456789;

ll f[93];

void init() {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 92; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
}

char find(ll n, ll k) {
	if (n == 1) return 'A';
	if (n == 2) return 'B';
	if (k > f[n - 2]) return find(n - 1, k - f[n - 2]);
	return find(n - 2, k);
} 

int main(){
	init();
	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		cout << find(n, k) << endl;
	} 
	return 0;
}

