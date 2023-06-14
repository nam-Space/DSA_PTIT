#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int x[1001];
int n, k;

void nhap() {
	cin >> n;
	memset(x, 0, sizeof(x));
}

void in() {
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) cout << "8";
		else cout << "6";
	}
	cout << endl;
}

bool check() {
	if (x[1] == 0 || x[n] == 1) return false;
	for (int i = 1; i <= n - 1; i++) {
		if (x[i] == 1 && x[i + 1] == x[i]) return false;
	}
	for (int i = 1; i <= n - 3; i++) {
		if (x[i] == 0 && x[i + 1] == x[i] && x[i + 2] == x[i + 1] && x[i + 3] == x[i + 2]) return false;
	}
	return true;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check()) in();
		}
		else Try(i + 1);
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
	}
}
