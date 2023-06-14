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
		int sum = 0;
		for (int &x : a) {
			cin >> x;
			sum += x;
		}
		bool check = false;
		int sum2 = 0;
		for (int i = 0; i < n; i++) {
			sum2 += a[i];
			if (sum2 == sum - sum2 + a[i]) {
				check = true;
				cout << i + 1 << endl;
				break;
			}
		}
		if (!check) cout << "-1" << endl;
	}
	return 0;
}

