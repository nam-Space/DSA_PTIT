#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;

int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		int a[n], b[m];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}
		int tong[n + m - 1] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tong[i + j] += a[i] * b[j];
			}
		}
		for (int i = 0; i < n + m - 1; i++) {
			cout << tong[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

