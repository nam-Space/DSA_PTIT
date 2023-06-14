#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void nhap(ll a[], int n) {
	for (int i = 0; i < n; i++) cin >> a[i];
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt[2] = {0};
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			cnt[x]++;
		}
		cout << cnt[0] << endl;
	} 
	return 0;
}

