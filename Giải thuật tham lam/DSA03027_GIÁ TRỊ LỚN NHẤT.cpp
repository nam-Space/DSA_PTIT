#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

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
	ll res = 0;
	for (int x : a) {
		if (x > 0) res += 2 * x;
	}
	cout << res << endl;
	}
}