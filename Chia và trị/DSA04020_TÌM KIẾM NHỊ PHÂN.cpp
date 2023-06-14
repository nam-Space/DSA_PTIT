#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void nhap(int a[], int n) {
	for (int i = 0; i < n; i++) cin >> a[i];
}

int binary_search(int a[], int n, int k) {
	int pos = -1;
	int l = 0, r = n - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] == k) {
			r = m - 1;
			pos = m + 1;
		}
		else if (a[m] < k) {
			l = m + 1;
		}
		else r = m - 1;
	}
	return pos;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		nhap(a, n);
		int res = binary_search(a, n, k);
		if (res == -1) cout << "NO" << endl;
		else cout << res << endl;
	} 
	return 0;
}

