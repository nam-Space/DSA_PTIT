#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n;
ll a[2][2], b[2][2];

void Mul(ll a[2][2], ll b[2][2]) {
	ll tmp[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
				tmp[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
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
		cin >> n;
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
		b[0][0] = b[0][1] = b[1][0] = 1;
		b[1][1] = 0;
		Pow(n);
		cout << a[0][1] << endl;
	}
	return 0;
}

