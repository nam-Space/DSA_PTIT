#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void heapify(int a[], int n, int i) {
	int l = 2 * i + 1, r = 2 * i + 2;
	int largest = i;
	if (l < n && a[largest] < a[l]) largest = l;
	if (r < n && a[largest] < a[r]) largest = r;
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heap_sort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		heap_sort(a, n);
		if (binary_search(a, a + n, k)) cout << "1" << endl;
		else cout << "-1" << endl;
	}
	return 0;
}

