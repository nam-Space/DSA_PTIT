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
		sort(a, a + n, greater<int>());
		int i = 0, j = n / 2, cnt = 0;
		while(i < n && j < n) {
			while(a[i] < 2 * a[j] && j < n) {
				j++;
			}
			if (j < n && a[i] >= 2 * a[j]) {
				cnt++;
				i++;
			}
			j++;
		}
		cout << n - cnt << endl;
	}
	return 0;
}

