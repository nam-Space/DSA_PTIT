#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k, x[101], used[101];
string a[101];
int res;

void nhap() {
	res = INT_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(used, 0, sizeof(used));
}

void process() {
	int cnt = 0;
	for (int i = 1; i <= n - 1; i++) {
		set<char> se;
		for (int j = 0; j < a[x[i]].size(); j++) {
			se.insert(a[x[i]][j]);
		}
		for (int j = 0; j < a[x[i + 1]].size(); j++) {
			if (se.find(a[x[i + 1]][j]) != se.end()) cnt++;
		}
	}
	res = min(res, cnt);
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n) process();
			else Try(i + 1);
			used[j] = 0;
		}
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
		cout << res << endl;
	}
}
