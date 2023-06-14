#include <bits/stdc++.h>
using namespace std;

int a[101];

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		for (int i = 1; i <= n; i++) {
			a[i] = s[i - 1] - '0';
		}
		for (int i = 2; i <= n; i++) {
			a[i] = (a[i] + a[i - 1]) % 2;
		}
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << endl;
	}
}
