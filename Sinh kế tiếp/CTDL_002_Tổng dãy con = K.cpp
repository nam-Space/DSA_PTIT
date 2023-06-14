#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k, ok, a[101], x[101], cnt;

void ktao() {
	cnt = ok = 0;
	memset(x, 0, sizeof(x));
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void sinh() {
	int i = n;
	while(x[i] == 1 && i >= 1) {
		x[i] = 0;
		i--;
	}
	if (i == 0) ok = 1;
	else {
		x[i] = 1;
	}
}

bool check() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) sum += a[i];
	}
	return sum == k;
}

int main(){
	ktao();
	while(!ok) {
		if (check()) {
			cnt++;
			for (int i = 1; i <= n; i++) {
				if (x[i] == 1) cout << a[i] << " ";
			}
			cout << endl;
		}
		sinh();
	}
	cout << cnt << endl;
}
