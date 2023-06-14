#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = n - 1; i >= 1; i -= 2) {
			int root = (i - 1) / 2;
			if (a[root] == "+") {
				a[root] = to_string(stoi(a[i - 1]) + stoi(a[i]));
			}
			else if (a[root] == "-") {
				a[root] = to_string(stoi(a[i - 1]) - stoi(a[i]));
			}
			else if (a[root] == "*") {
				a[root] = to_string(stoi(a[i - 1]) * stoi(a[i]));
			}
			else a[root] = to_string(stoi(a[i - 1]) / stoi(a[i]));
		}
		cout << a[0] << endl;
	}
	return 0;
}
