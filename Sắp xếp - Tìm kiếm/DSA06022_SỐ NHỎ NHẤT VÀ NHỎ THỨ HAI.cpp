#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pq.push(a[i]);
		}
		int min1 = pq.top(); pq.pop();
		if (pq.empty()) {
			cout << "-1" << endl;
			continue;
		}
		int min2 = pq.top(); pq.pop();
		if (min1 == min2) cout << "-1" << endl;
		else cout << min1 << " " << min2 << endl;
	}
	return 0;
}

