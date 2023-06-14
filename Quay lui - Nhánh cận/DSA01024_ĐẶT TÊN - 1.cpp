#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

string a[1001];
int x[1001];
int n, k;
set<string> se;
vector<vector<string>> res;

void nhap() {
	se.clear();
	res.clear();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		se.insert(s);
	}
	n = se.size();
	int cnt = 1;
	for (string x : se) {
		a[cnt++] = x;
	}
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}
}

void process() {
	vector<string> v;
	for (int i = 1; i <= k; i++) {
		v.push_back(a[x[i]]);
	}
	res.push_back(v);
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) process();
		else Try(i + 1);
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
		for (vector<string> v : res) {
			for (string s : v) {
				cout << s << " ";
			}
			cout << endl;
		}
	}
}
