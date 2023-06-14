#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void selection_sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_pos]) {
				min_pos = j;
			}
		}
		swap(a[i], a[min_pos]);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		selection_sort(a, n);
		if (n % 2 == 1) {
			for (int i = 0; i <= n / 2; i++) {
				if (i != n / 2) cout << a[n - i - 1] << " " << a[i] << " ";
				else cout << a[n / 2];
			}
		}
		else {
			for (int i = 0; i <= n / 2; i++) {
				if (i != n / 2) cout << a[n - i - 1] << " " << a[i] << " ";
			}
		}
		cout <<endl;
	}
	return 0;
}

