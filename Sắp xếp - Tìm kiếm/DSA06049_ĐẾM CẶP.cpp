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

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int &x : a) cin >> x;
		merge_sort(a, 0, n - 1);
		ll cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			cnt += lower_bound(a + i + 1, a + n, k + a[i]) - a - 1 - i;
		}
		cout << cnt << endl;
	}
	return 0;
}

