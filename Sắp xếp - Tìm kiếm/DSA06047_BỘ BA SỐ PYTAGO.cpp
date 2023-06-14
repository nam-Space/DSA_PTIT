#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void merge(int a[], int l, int m, int r) {
	vector<int> x(a + l, a + m + 1);
	vector<int> y(a + m + 1, a + r + 1);
	int i = 0, j = 0;
	while(i < x.size() && j < y.size()) {
		if (x[i] < y[j]) a[l++] = x[i++];
		else a[l++] = y[j++];
	}
	while(i < x.size()) a[l++] = x[i++];
	while(j < y.size()) a[l++] = y[j++];
}

void merge_sort(int a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
}

bool check(ll a[], int n) {
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (binary_search(a + j + 1, a + n, a[i] + a[j])) return true;
		}
	}
	return false;	
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			a[i] = 1ll * x * x;
		}
		sort(a, a + n);
		if (check(a, n)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

