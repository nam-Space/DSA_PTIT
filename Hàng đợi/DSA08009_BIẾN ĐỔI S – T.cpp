#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int bfs(int se, int en) {
	int a[20000];
	memset(a, -1, sizeof(a));
	queue<int> q;
	q.push(se);
	a[se] = 0;
	while(!q.empty()) {
		int i = q.front(); q.pop();
		if (a[en] != -1) return a[en];
		if (i - 1 > 0 && a[i - 1] == -1) {
			a[i - 1] = a[i] + 1;
			q.push(i - 1);
		}
		if (i * 2 < 20000 && a[i * 2] == -1) {
			a[i * 2] = a[i] + 1;
			q.push(i * 2);
		}
	}
	return a[en];
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int se, en;
		cin >> se >> en;
		cout << bfs(se, en) << endl;
	}
}

