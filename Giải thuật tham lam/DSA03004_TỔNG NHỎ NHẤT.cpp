#include <bits/stdc++.h>
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
		} while(a[j] > pivot);
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
    	int n;
    	cin >> n;
    	int *a = new int[n];
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
		}
		quick_sort(a, 0, n - 1);
		ll sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) sum1 = sum1 * 10 + a[i];
			else sum2 = sum2 * 10 + a[i];
		}
		cout << sum1 + sum2 << endl;
	}
}


