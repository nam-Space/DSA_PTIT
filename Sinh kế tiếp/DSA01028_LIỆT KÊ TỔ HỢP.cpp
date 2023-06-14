#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[10001], x[10001];
int n, k, used[10001];
set<int> se;

void nhap() {
	se.clear();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		se.insert(a[i]);
	}
	n = se.size();
	int cnt = 1;
	for (int x : se) {
		a[cnt++] = x;
	}
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}
}

void in() {
	for (int i = 1; i <= k; i++) {
		cout << a[x[i]] << " ";
	}
	cout << endl;
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) in();
		else Try(i + 1);
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
	}
}
