#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<ll> res;
ll ans[1001];

void init() {
	queue<string> q;
	q.push("1");
	res.push_back(1);
	while(1) {
		string top = q.front(); q.pop();
		if (top.size() == 19) break;
		q.push(top + "0");
		q.push(top + "1");
		res.push_back(stoll(top + "0"));
		res.push_back(stoll(top + "1"));
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for (ll x : res) {
			if (x % n == 0) {
				cout << x << endl;
				break;
			}
		}
	} 
}

