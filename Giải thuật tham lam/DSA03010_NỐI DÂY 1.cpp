#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			pq.push(x);
		}
		ll res = 0;
		while(pq.size() >= 2) {
			int x = pq.top(); pq.pop();
			int y = pq.top(); pq.pop();
			res += x + y;
			pq.push(x + y);
		}
		cout << res << endl;
	} 
}

