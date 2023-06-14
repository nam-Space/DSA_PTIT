#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int a[n + 1], b[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = s[i - 1] - '0';
			b[i] = s[i - 1] - '0';
		}
		for (int i = 2; i <= n; i++) {
			b[i] = (a[i - 1] + a[i]) % 2;
		}
		for (int i = 1; i <= n; i++) {
			cout << b[i];
		}
		cout << endl;
	}
	return 0;
}
