#include <bits/stdc++.h>
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
    	vector<int> tang(a, a + n);
    	vector<int> giam(a, a + n);
    	int res = INT_MIN;
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < i; j++) {
    			if (a[i] > a[j]) {
    				tang[i] = max(tang[i], tang[j] + a[i]);
				}
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j > i; j--) {
				if (a[i] > a[j]) {
					giam[i] = max(giam[i], giam[j] + a[i]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			res = max(res, tang[i] + giam[i] - a[i]);
		}
		cout << res << endl;
	}
}


