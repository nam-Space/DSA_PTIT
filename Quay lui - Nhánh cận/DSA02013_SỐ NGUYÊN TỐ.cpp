#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, p, s, cnt;
int a[201], x[201], prime[201];
vector<vector<int>> res;

void init() {
	for (int i = 0; i <= 200; i++) prime[i] = 1;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 15; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 200; j += i) {
				prime[j] = 0;
			}
		}
	}
	cnt = 0;
	for (int i = 0; i <= 200; i++) {
		if (prime[i]) {
			a[++cnt] = i;
		}
	} 
}

void nhap() {
	res.clear();
	cin >> n >> p >> s;
	for (int i = 1; i <= 200; i++) x[i] = i;
}

bool check() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[x[i]] <= p) return false;
		sum += a[x[i]];
	}
	return sum == s;
}

void ghiNhan() {
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(a[x[i]]);
	}
	res.push_back(v);
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= cnt - n + i; j++) {
		x[i] = j;
		if (i == n) {
			if (check()) ghiNhan();
		}
		else Try(i + 1);
	}
}

int main(){
	init();
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		sort(res.begin(), res.end());
		cout << res.size() << endl;
		for (vector<int> v : res) {
			for (int x : v) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}



