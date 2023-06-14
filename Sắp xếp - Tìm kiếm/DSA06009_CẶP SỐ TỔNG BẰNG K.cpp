#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int pos = i - 1;
		int x = a[i];
		while(pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

int first_pos(int a[], int l, int r, int x) {
	int pos = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			r = m - 1;
			pos = m;
		}
		else if (a[m] > x) {
			r = m - 1;
		}
		else l = m + 1;
	}
	return pos;
}

int last_pos(int a[], int l, int r, int x) {
	int pos = -1;
	while(l <= r) {
		int m = (l + r) / 2;
		if (a[m] == x) {
			l = m + 1;
			pos = m;
		}
		else if (a[m] > x) r = m - 1;
		else l = m + 1;
	}
	return pos;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int &x : a) cin >> x;
		insertion_sort(a, n);
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			int l = first_pos(a, i + 1, n - 1, k - a[i]);
			int r = last_pos(a, i + 1, n - 1, k - a[i]);
			if (l != -1) {
				cnt += r - l + 1;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

