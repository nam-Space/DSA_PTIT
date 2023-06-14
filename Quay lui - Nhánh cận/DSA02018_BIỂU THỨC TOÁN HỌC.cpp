#include <bits/stdc++.h> 
using namespace std;

//1 -> +
//2 -> -;
//3 -> *

using ll = long long;
bool ok, p[10];
int a[5], vt[10];
vector<vector<int>> res;
vector<int> u;

void init() {
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++) {
		vt[i] = 0;
		p[i] = false;
	}
	ok = false;
	u.clear();
}

void TryDau() {
	for (int i = 1; i <= 3; i++) {
		u.push_back(i);
		if (u.size() == 4) {
			res.push_back(u);
		}
		else TryDau();
		u.pop_back();
	}
}

bool check() {
	for(int i = 0; i < res.size(); i++) {
		int s = a[vt[0]];
		for (int j = 0; j < 4; j++) {
			if (res[i][j] == 1) s += a[vt[j + 1]];
			if (res[i][j] == 2) s -= a[vt[j + 1]];
			if (res[i][j] == 3) s *= a[vt[j + 1]];
		}
		if (s == 23) return true;
	}
	return false;
}

void Try(int i) {
	if (ok) return;
	for (int j = 0; j < 5; j++) {
		if (!p[j]) {
			vt[i] = j;
			p[j] = true;
			if (i == 4) {
				if (check()) {
					ok = true;
					return;
				}
 			}
 			else Try(i + 1);
 			p[j] = false;
		}
	}
}

int main(){ 
	TryDau();
	int t;
	cin >> t;
	while(t--) {
		init();
		Try(0);
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

