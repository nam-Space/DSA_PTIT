#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

bool check(int p, int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] / p < (a[i] / (p + 1) + 1)) return false;
	}
	return true;
}

int main(){
    int t;
    t = 1;
    while(t--) {
    	int n;
    	cin >> n;
    	int a[n];
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
		}
		int s = *min_element(a, a + n);
		int res = 0;
		for (int i = s; i >= 1; i--) {
			if (check(i, a, n)) {
				for (int x : a) {
					res += x / (i + 1) + 1;
				}
				break;
			}
		}
		cout << res << endl;
	}
}