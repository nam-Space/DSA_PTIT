#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void nhap(ll a[], int n) {
	for (int i = 0; i < n; i++) cin >> a[i];
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll a[n], b[n - 1];
		nhap(a, n);
		nhap(b, n - 1);
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				cout << i + 1 << endl;
				break;
			}
		}
	} 
	return 0;
}

