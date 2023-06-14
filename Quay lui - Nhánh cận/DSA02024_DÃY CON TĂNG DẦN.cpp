#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[101];
int x[101];
int n, m, k, used[101];
vector<string> res;

void nhap() {
	res.clear();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(x, 0, sizeof(x));
}

void process() {
	string s = "";
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) s += to_string(a[i]) + " ";
	}
	s = s.substr(0, s.length() - 1);
	res.push_back(s);
}

bool check() {
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) {
			v1.push_back(a[i]);
			v2.push_back(a[i]);
		}
	}
	sort(v1.begin(), v1.end());
	if (v1.size() <= 1) return false;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if (check()) process();
		}
		else Try(i + 1);
	}
}


int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
		sort(res.begin(), res.end());
		for (string s : res) {
			cout << s << endl;
		}
	}
}

