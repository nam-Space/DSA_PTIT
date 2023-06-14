#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	int n = s.size();
    	int a[n + 1];
    	for(int i = 1; i <= n; i++) {
    		a[i] = s[i - 1] - '0';
		}
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			ll sum = 0;
			for (int j = i; j <= n; j++) {
				sum = sum * 10 + a[j];
				res += sum;
			}
		}
		cout << res << endl;
	}
}


