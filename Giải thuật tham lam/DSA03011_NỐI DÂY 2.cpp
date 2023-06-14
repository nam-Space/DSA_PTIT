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
    		res %= mod;
    		pq.push((x + y) % mod);
		}
		cout << res << endl;
	}
}


