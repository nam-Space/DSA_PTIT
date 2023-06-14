#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001], x[1001];
int n, k, ok;
map<vector<int>, int> mp;

void nhap() {
	mp.clear();
	ok = 0;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> x[i];
	}
	for (int i = 1; i <= k; i++) {
		a[i] = i;
	}
}

void sinh() {
	int i = k;
	while(a[i] == n - k + i && i >= 1) {
		i--;
	}
	if (i == 0) ok = 1;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
	}
}

bool check(vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != x[i + 1]) return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		int cnt = 0;
		while(!ok) {
			cnt++;
			vector<int> v;
			for (int i = 1; i <= k; i++) {
				v.push_back(a[i]);
			}
			mp.insert({v, cnt});
			sinh();
		}
		for (auto it : mp) {
			if (check(it.first)) {
				cout << it.second << endl;
				break;
			}
		}
	}
}
