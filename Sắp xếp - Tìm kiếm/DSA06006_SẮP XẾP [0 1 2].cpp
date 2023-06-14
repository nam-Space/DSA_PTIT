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
		int cnt[3] = {0};
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

