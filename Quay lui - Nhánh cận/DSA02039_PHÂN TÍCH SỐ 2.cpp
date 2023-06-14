#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, ok, cnt, a[101];
vector<vector<int>> res;

void nhap() {
	ok = 0;
	res.clear();
	cin >> n;
	cnt = 1;
	a[1] = n;
}

void sinh() {
	int i = cnt;
	while(i >= 1 && a[i] == 1) {
		i--;
	}
	if (i == 0) ok = 1;
	else {
		a[i]--;
		int d = cnt - i + 1;
		cnt = i;
		int q = d / a[i];
		int r = d % a[i];
		for (int j = 0; j < q; j++) {
			a[++cnt] = a[i];
		}
		if (r) {
			a[++cnt] = r;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		while(!ok) {
			vector<int> v;
			for (int i = 1; i <= cnt; i++) {
				v.push_back(a[i]);
			}
			res.push_back(v);
			sinh();
		}
		cout << res.size() << endl;
		for (vector<int> v : res) {
			cout << "(";
			for (int i = 0; i < v.size() - 1; i++) {
				cout << v[i] << " ";
			} 
			cout << v[v.size() - 1] << ") ";
		}
		cout << endl;
	}
	return 0;
}



