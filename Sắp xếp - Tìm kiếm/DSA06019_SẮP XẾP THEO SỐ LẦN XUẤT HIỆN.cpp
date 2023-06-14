#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int cnt[100001];

bool cmp(int a, int b) {
	if (cnt[a] == cnt[b]) return a < b;
	return cnt[a] > cnt[b];
}
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		sort(a, a + n, cmp);
		for (int x : a) cout << x << " ";
		cout << endl;
	}
	return 0;
}

