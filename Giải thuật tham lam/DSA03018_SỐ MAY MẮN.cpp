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
    	int so4 = 0, so7 = 0;
    	int res4 = 1e9, res7 = 1e9;
    	for (int i = 0; i <= n / 4; i++) {
    		if ((n - 4 * i) % 7 == 0) {
    			so4 = i;
    			so7 = (n - 4 * i) / 7;
    			if (res7 > so7 && res4 + res7 > so4 + so7) {
    				res7 = so7;
    				res4 = so4;
				}
			}
		}
		if (res4 == 1e9 && res7 == 1e9) {
			cout << "-1" << endl;
			continue;
		}
		for (int i = 0; i < res4; i++) cout << "4";
		for (int i = 0; i < res7; i++) cout << "7";
		cout << endl;
	}
}


