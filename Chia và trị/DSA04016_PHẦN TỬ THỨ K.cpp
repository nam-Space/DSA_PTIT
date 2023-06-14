#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void nhap(int a[], int n) {
	for (int i = 0; i < n; i++) cin >> a[i];
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int m, n, k;
		cin >> m >> n >> k;
		int *a = new int[m];
		int *b = new int[n];
		nhap(a, m);
		nhap(b, n);
		vector<int> res;
		int i = 0, j = 0;
		while(i < m && j < n) {
			if (a[i] < b[j]) {
				res.push_back(a[i]);
				i++;
			}
			else {
				res.push_back(b[j]);
				j++;
			}
		}
		while(i < m) {
			res.push_back(a[i]);
			i++;
		}
		while(j < n) {
			res.push_back(b[j]);
			j++;
		}
		cout << res[k - 1] << endl;
	} 
	return 0;
}

