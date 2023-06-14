#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int selection_sort(int a[], int n) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_pos]) min_pos = j;
		}
		if (i != min_pos) {
			swap(a[i], a[min_pos]);
			cnt++;
		}
	}
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		cout << selection_sort(a, n) << endl;
	}
	return 0;
}

