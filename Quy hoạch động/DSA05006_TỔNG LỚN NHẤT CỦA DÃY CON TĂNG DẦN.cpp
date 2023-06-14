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
		vector<int> res(a, a + n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j]) {
					res[i] = max(res[i], res[j] + a[i]);
				}
			}
		}
		cout << *max_element(res.begin(), res.end()) << endl;
	} 
	return 0;
}

