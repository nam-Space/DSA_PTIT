#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, x;
ll a[11][11], b[11][11];

void Mul(ll a[11][11], ll b[11][11]) {
	ll tmp[11][11];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			tmp[i][j] = 0;
			for (int k = 1; k <= n; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= mod;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = tmp[i][j];
		}
	}
}

void Pow(int k) {
	if (k < 2) return;
	Pow(k / 2);
	Mul(a, a);
	if (k % 2 == 1) Mul(a, b);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
		}
		Pow(x);
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += a[i][n];
			sum %= mod;
		}
		cout << sum << endl;
	} 
	return 0;
}

