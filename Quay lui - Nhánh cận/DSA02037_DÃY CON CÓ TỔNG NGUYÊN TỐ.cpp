#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n;
int a[101], x[101], prime[1000001];
vector<vector<int>> res;

void init() {
	for (int i = 0; i <= 1000000; i++) {
		prime[i] = 1;
	}
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1000; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				prime[j] = 0;
			}
		}
	}
}

void nhap() {
	res.clear();
	memset(x, 0, sizeof(x));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
}

void ghiNhan() {
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) {
			v.push_back(a[i]);
		}
	}
	res.push_back(v);
}

bool check() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) {
			sum += a[i];
		}
	}
	return prime[sum] == 1;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check()) ghiNhan();
		}
		else Try(i + 1);
	}
}
 
int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		sort(res.begin(), res.end());
		for (vector<int> v : res) {
			for (int x : v) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
