#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int prime[1000001];

void init() {
	for (int i = 0; i < 1000001; i++) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 1000; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				prime[j] = 0;
			}
		}
	}
}

pair<int, int> res(int n) {
	pair<int, int> v;
	for (int i = 2; i <= n / 2; i++) {
		if (prime[i] && prime[n - i]) {
			v.first = i;
			v.second = n - i;
			return v;
		}
	}
	v.first = -1;
	v.second = -1;
	return v;
}

int main(){
	init();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if (res(n).first == -1) {
			cout << "-1" << endl;
			continue;
		}
		cout << res(n).first << " " << res(n).second << endl;
	}
	return 0;
}

