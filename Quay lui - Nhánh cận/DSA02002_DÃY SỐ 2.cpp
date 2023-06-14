#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[10001], x[10001];
int n, k, used[10001];
vector<string> res;

void nhap() {
	res.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void in() {
	for (int i = 1; i <= k; i++) {
		cout << a[x[i]] << " ";
	}
	cout << endl;
}

void Try(int n) {
	if (n == 0) return;
	string s = "";
	s += "[";
	for (int i = 1; i <= n - 1; i++) {
		s += to_string(a[i]) + " ";
	}
	s += to_string(a[n])+ "]";
	res.push_back(s);
	for (int i = 1; i <= n - 1; i++) {
		a[i] = a[i] + a[i + 1];
	}
	Try(n - 1);
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(n);
		reverse(res.begin(), res.end());
		for (string s : res) {
			cout << s << " ";
		}
		cout << endl;
	}
}
