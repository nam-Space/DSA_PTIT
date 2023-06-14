#include <bits/stdc++.h> 
using namespace std;

int a[1001], n, k, ok;
set<int> se;

void nhap() {
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		se.insert(a[i]);
	}
}

int count() {
	if (ok == 1) {
		return k;
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (se.find(a[i]) == se.end()) {
			cnt++;
		}
	}
	return cnt;
}

void sinh() {
	int i = k
	while(a[i] == n - k + i) {
		i--;
	}
	if (i == 0) ok = 1;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		ok = 0;
		nhap();
		sinh();
		cout << count() << endl;
		se.clear();
	}
	return 0;
}

