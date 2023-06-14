#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void buble_sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int &x : a) cin >> x;
		buble_sort(a, n);
		for (int i = n - 1; i >= n - k; i--) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

