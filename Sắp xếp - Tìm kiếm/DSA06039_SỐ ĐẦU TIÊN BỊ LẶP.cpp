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
		map<int, int> mp;
		for (int &x : a) {
			cin >> x;
			mp[x]++;
		}
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (mp[a[i]] >= 2) {
				cout << a[i] << endl;
				check = true;
				break;
			}
		}
		if (!check) cout << "NO" << endl;
	}
	return 0;
}

