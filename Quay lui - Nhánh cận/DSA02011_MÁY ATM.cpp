#include <bits/stdc++.h> 
using namespace std;

int n, s, k;
int a[101], x[101];

void nhap() {
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

bool check() {
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += a[x[i]];
	}
	return sum == s;
}

bool Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			if (check()) return true;
		}
		else if (Try(i + 1)) return true;
	}
	return false;
}

int solve() {
	for (int i = 1; i <= n; i++) {
		k = i;
		for (int j = 1; j <= k; j++) x[j] = j;
		if (Try(1)) return i;
	}
	return -1;
}

int main(){ 
	int t;
	cin >> t;
	while(t--) {
		nhap();
		cout << solve() << endl;
	}
	return 0;
}



