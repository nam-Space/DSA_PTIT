#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n;
int a[101], x[101];
vector<vector<int>> res;

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
	return sum % 2 != 0;
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
