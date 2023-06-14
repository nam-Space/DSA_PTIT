#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k;
int a[101][101], x[101];
bool used[101];
vector<vector<int>> res;

void nhap() {
	res.clear();
	memset(x, 0, sizeof(x));
	memset(used, false, sizeof(used));
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}

bool check() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i][x[i]];
	}
	return sum == k;
}

void process() {
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		v.push_back(x[i]);
	}
	res.push_back(v);
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = true;
			if (i == n) {
				if (check()) process();
			}
			else Try(i + 1);
			used[j] = false;
		}
	}
}

int main() {
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
		cout << res.size() << endl;
		for (vector<int> v : res) {
			for (int x : v) {
				cout << x << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

