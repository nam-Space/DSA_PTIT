#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void buble_sort(int a[], int n) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		bool check = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				check = true;
			}
		}
		if (check) {
			cnt++;
			cout << "Buoc " << cnt << ": ";
			for (int j = 0; j < n; j++) {
				cout << a[j] << " ";
			}
			cout << endl;
		}
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		buble_sort(a, n);
	}
	return 0;
}

