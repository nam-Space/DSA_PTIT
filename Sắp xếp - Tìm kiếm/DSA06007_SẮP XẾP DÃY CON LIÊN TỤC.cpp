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
		int l, r;
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				l = i;
				break;
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] < a[i - 1]) {
				r = i;
				break;
			}
		}
		int min_val = *min_element(a + l, a + r + 1);
		int max_val = *max_element(a + l, a + r + 1);
		for (int i = 0; i < l; i++) {
			if (a[i] > min_val) {
				l = i;
			}
		}
		for (int i = n - 1; i > r; i--) {
			if (a[i] < max_val) {
				r = i;
			}
		}
		cout << l + 1 << " " << r + 1 << endl;
	}
	return 0;
}

