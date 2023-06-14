#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

string a[101];
int x[101];
int n, m, k, used[101];
set<string> se;
int cnt;

void nhap() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		se.insert(s);
	}
	n = se.size();
	int cnt = 1;
	for (string s : se) {
		a[cnt++] = s;
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

