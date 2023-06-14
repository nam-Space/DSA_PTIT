#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<ll> res;
ll ans[501];

void init() {
	queue<string> q;
	q.push("9");
	res.push_back(9);
	while(1) {
		string top = q.front(); q.pop();
		if (top.size() == 18) break;
		q.push(top + "0");
		q.push(top + "9");
		res.push_back(stoll(top + "0"));
		res.push_back(stoll(top + "9"));
	}
	for (int i = 1; i <= 500; i++) {
		for (ll x : res) {
			if (x % i == 0) {
				ans[i] = x;
				break;
			}
		}
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
