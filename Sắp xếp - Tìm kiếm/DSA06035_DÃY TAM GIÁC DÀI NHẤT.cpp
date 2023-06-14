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
		vector<int> tang(n, 1);
		vector<int> giam(n, 1);
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) {
				tang[i] = tang[i - 1] + 1;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > a[i + 1]) {
				giam[i] = giam[i + 1] + 1;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, tang[i] + giam[i] - 1);
		}
		cout << res << endl;
	}
	return 0;
}

