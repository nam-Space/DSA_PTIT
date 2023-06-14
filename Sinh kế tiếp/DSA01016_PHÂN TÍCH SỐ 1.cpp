#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, cnt, ok;
int a[101];

void nhap() {
	cin >> n;
	a[1] = n;
	cnt = 1;
	ok = 0;
}

void sinh() {
	int i = cnt;
	while(i >= 1 && a[i] == 1) {
		i--;
	}
	if (i == 0) ok = 1;
	else {
		a[i]--;
		int d = cnt - i + 1;
		cnt = i;
		int q = d / a[i];
		int r = d % a[i];
		if (q) {
			for (int j = 1; j <= q; j++) {
				a[++cnt] = a[i];
			}
		}
		if (r) {
			a[++cnt] = r;
		}
	}
}

void in() {
	cout << "(";
	for (int i = 1; i <= cnt - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[cnt] << ") ";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		while(!ok) {
			in();
			sinh();
		}
		cout << endl;
	}
	return 0;
}
