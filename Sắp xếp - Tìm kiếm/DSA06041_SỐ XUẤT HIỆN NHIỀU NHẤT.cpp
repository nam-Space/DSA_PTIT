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
    	map<int, int> mp;
    	int a[n];
    	for (int &x : a) {
    		cin >> x;
    		mp[x]++;
		}
		int max_exist = INT_MIN, val;
		for (int x : a) {
			if (max_exist < mp[x]) {
				max_exist = mp[x];
				val = x;
			}
		}
		if (max_exist > n / 2) {
			cout << val << endl;
		}
		else cout << "NO" << endl;
	}
}
