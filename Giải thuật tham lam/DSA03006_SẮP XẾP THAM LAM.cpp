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
		swap(a[largest], a[i]);
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

bool check(int a[], int b[], int n) {
	for (int i = 0; i <= n / 2; i++) {
		if (a[i] != b[i] && a[n - i - 1] != b[i]) return false;
	}
	return true;
} 

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	int a[n], b[n];
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		b[i] = a[i];
		}
		heap_sort(b, n);
		if (check(a, b, n)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}


