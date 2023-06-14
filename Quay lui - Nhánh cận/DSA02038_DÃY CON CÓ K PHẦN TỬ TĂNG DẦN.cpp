#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k;
int a[101], x[101];
vector<vector<int>> res;

void nhap() {
	res.clear();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x[i] = i;
	}
	sort(a + 1, a + n + 1);
}

void ghiNhan() {
	vector<int> v;
	for (int i = 1; i <= k; i++) {
		v.push_back(a[x[i]]);
	}
	res.push_back(v);
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			ghiNhan();
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
