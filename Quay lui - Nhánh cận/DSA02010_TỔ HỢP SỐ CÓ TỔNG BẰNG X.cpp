#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k;
int a[101];
vector<vector<int>> res;

void nhap() {
	res.clear();
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void Try(int i, int sum, vector<int> v) {
	if (sum == k) {
		res.push_back(v);
		return;
	}
	for (int j = i; j <= n; j++) {
		if (sum + a[j] <= k) {
			v.push_back(a[j]);
			Try(j, sum + a[j], v);
			v.pop_back();
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		vector<int> v;
		Try(1, 0, v);
		if (res.size() == 0) {
			cout << "-1" << endl;
			continue;
		}
		cout << res.size() << " ";
		for (vector<int> ve : res) {
			cout << "{";
			for (int i = 0; i < ve.size() - 1; i++) {
				cout << ve[i] << " ";
			}
			cout << ve[ve.size() - 1] << "} ";
		}
		cout << endl;
	}
	return 0;
}



