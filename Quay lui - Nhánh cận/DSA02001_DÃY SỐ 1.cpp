#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[10001], x[10001];
int n, k, used[10001];

void nhap() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void in() {
	for (int i = 1; i <= k; i++) {
		cout << a[x[i]] << " ";
	}
	cout << endl;
}

void Try(int n) {
	if (n == 0) return;
	cout << "[";
	for (int i = 1; i <= n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n] << "]" << endl;
	for (int i = 1; i <= n - 1; i++) {
		a[i] = a[i] + a[i + 1];
	}
	Try(n - 1);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(n);
	}
}
