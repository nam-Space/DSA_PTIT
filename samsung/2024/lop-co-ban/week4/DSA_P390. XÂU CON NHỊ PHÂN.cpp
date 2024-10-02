#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, cnt, a[101];
string s;

void nhap() {
	cnt = 0;
	cin >> n >> s;
	memset(a, 0, sizeof(a));
}

void process() {
	string tmp = "";
	for (int i = 1; i <= n; i++) {
		tmp += to_string(a[i]);
	}
	if (tmp != "") {
		if (tmp.find(s) != string::npos) cnt++;
	}
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) process();
		else Try(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		cout << cnt << endl;
	}
	return 0;
}