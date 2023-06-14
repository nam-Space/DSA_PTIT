#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int d;
    	cin >> d;
    	string s;
    	cin >> s;
    	int cnt[301] = {0};
    	for (char x : s) cnt[x]++;
    	priority_queue<int, vector<int>> pq;
    	for (int x : cnt) {
    		if (x != 0) pq.push(x);
		}
		while(d--) {
			int tmp = pq.top(); pq.pop();
			tmp--;
			pq.push(tmp);
		}
		ll res = 0;
		while(!pq.empty()) {
			res += 1ll * pq.top() * pq.top();
			pq.pop();
		}
		cout << res << endl;
	}
}


