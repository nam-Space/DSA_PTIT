#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k;
ll a[10][10], b[10][10];

void Mul(ll a[10][10], ll b[10][10]) {
	ll tmp[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
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
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
		}
		Pow(k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

