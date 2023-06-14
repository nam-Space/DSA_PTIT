#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << *max_element(a, a + k) << " ";
		for (int i = 1; i < n - k + 1; i++) {
			cout << *max_element(a + i, a + i + k) << " ";
		}
		cout << endl;
	}
	return 0;
}

