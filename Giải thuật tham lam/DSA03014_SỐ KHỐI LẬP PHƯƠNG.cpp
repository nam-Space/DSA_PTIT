#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, a[101], x[101];
ll res;
map<ll, bool> third;

void init() {
	for (int i = 1; i <= 99999; i++) {
		third[1ll * i * i * i] = true;
	}
	third[0] = false;
}

void nhap() {
	res = -1;
	memset(x, 0, sizeof(x));
	string s;
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
	}
}

void ghiNhan() {
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) s = s * 10 + a[i];
	}
	if (third[s] == true) res = max(res, s);
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) ghiNhan();
		else Try(i + 1);
	}
}

int main(){
	init();
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		cout << res << endl;
	} 
}

