#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void heapify(int a[], int n, int i) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < n && a[largest] < a[l]) {
		largest = l;
	}
	if (r < n && a[largest] < a[r]) {
		largest = r;
	}
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heap_sort(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
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
		k = min(k, n - k);
		int sum1 = 0;
		for (int i = 0; i < k; i++) {
			sum1 += a[i];
		}
		int sum2 = 0;
		for (int i = k; i < n; i++) {
			sum2 += a[i];
		}
		cout << sum2 - sum1 << endl;
	}
}


