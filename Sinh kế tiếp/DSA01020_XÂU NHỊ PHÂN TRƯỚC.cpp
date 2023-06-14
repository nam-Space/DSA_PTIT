#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n, k;

void nhap() {
	string s;
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
	}
}

void sinh() {
	int i = n;
	while(a[i] == 0 && i >= 1) {
		a[i] = 1;
		i--;
	}
	if (i == 0) {
		for (int j = 1; j <= n; j++) {
			a[j] = 1;
		}
	}
	else {
		a[i] = 0;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		sinh();
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << endl;
	}
}
