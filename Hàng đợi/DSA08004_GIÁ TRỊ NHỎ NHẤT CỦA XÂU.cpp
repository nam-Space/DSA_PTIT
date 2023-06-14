#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		string s;
		cin >> s;
		int cnt[301] = {0};
		for (char x : s) cnt[x]++;
		priority_queue<int, vector<int>> pq;
		for (int x : cnt) {
			if (x != 0) pq.push(x);
		}
		for (int i = 0; i < k; i++) {
			int top = pq.top(); pq.pop();
			top--;
			pq.push(top);
		}
		ll res = 0;
		while(!pq.empty()) {
			res += 1ll * pq.top() * pq.top();
			pq.pop();
		}
		cout << res << endl;
	}
}

