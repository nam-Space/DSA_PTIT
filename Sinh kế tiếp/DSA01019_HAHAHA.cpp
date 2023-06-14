#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n, k;

void nhap() {
	cin >> n;
	memset(a, 0, sizeof(a));
}

void in() {
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) cout << "H";
		else cout << "A";
	}
	cout << endl;
}

bool check() {
	if (a[1] == 0 || a[n] == 1) return false;
	for (int i = 1; i < n; i++) {
		if (a[i] == 1 && a[i + 1] == a[i]) return false;
	}
	return true;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			if (check()) in();
		}
		else Try(i + 1);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
	}
}
