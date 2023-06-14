#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int partition(int a[], int l, int r) {
	int pivot = a[l];
	int i = l - 1, j = r + 1;
	while(1) {
		do {
			i++;
		} while(a[i] < pivot);
		do {
			j--;
		} while(pivot < a[j]);
		if (i < j) swap(a[i], a[j]);
		else return j;
	}
}

void quick_sort(int a[], int l, int r) {
	if (l >= r) return;
	int p = partition(a, l, r);
	quick_sort(a, l, p);
	quick_sort(a, p + 1, r);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int &x : a) cin >> x;
		quick_sort(a, 0, n - 1);
		ll cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			int pos = lower_bound(a + i + 1, a + n, a[i] + k) - a - i - 1;
			cnt += pos;
		}
		cout << cnt << endl;
	}
	return 0;
}

