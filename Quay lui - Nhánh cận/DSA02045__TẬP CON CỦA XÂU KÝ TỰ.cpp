#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, x[101];
char a[101];
vector<string> res;

void nhap() {
	res.clear();
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		a[i] = s[i - 1];
	}
	memset(x, 0, sizeof(x));
}

void ghiNhan() {
	string s = "";
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) {
			s += a[i];
		}
	}
	res.push_back(s);
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) ghiNhan();
		else Try(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) { 
		nhap();
		Try(1);
		sort(res.begin(), res.end());
		for (string s : res) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
