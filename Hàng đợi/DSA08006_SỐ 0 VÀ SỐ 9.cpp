#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<ll> res;
ll ans[101];

void init() {
	queue<string> q;
	q.push("9");
	res.push_back(9);
	while(1) {
		string tmp = q.front(); q.pop();
		if (tmp.size() == 18) break;
		q.push(tmp + "0");
		q.push(tmp + "9");
		res.push_back(stoll(tmp + "0"));
		res.push_back(stoll(tmp + "9"));
	}
	for (int i = 1; i <= 100; i++) {
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
}

