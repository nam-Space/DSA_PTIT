#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		int tmp = INT_MAX, res;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (abs(a[i] + a[j]) < tmp) {
					tmp = abs(a[i] + a[j]);
					res = a[i] + a[j];
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}

