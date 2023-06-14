#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void insertion_sort(int a[], int n) {
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		cout << "Buoc " << cnt << ": ";
		for (int j = 0; j < i; j++) {
			cout << a[j] << " ";
		}
		cout << endl;
		cnt++;
		int pos = i - 1;
		int x = a[i];
		while(pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
	cout << "Buoc " << cnt << ": ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
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
		insertion_sort(a, n);
	}
	return 0;
}

