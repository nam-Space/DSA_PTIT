#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<ll> res;
ll ans[1001];

void init() {
	queue<string> q;
	q.push("6");
	q.push("8");
	res.push_back(6);
	res.push_back(8);
	while(1) {
		string top = q.front(); q.pop();
		if (top.size() == 18) break;
		q.push(top + "6");
		q.push(top + "8");
		res.push_back(stoll(top + "6"));
		res.push_back(stoll(top + "8"));
	}
}

int len(ll x) {
	string s = to_string(x);
	return s.size();
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> v;
		int cnt = 0;
		for (ll x : res) {
			if (len(x) <= n) v.push_back(x);
			else break;		
		}
		cout << v.size() << endl;
		for (ll x : v) cout << x << " ";
		cout << endl;
	}
}

