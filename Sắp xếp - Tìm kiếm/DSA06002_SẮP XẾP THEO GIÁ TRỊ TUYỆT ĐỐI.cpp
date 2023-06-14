#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (abs(a.first - k) == abs(b.first - k)) return a.second < b.second;
	return abs(a.first - k) < abs(b.first - k); 
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int a[n];
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			v.push_back({a[i], i});
		}
		stable_sort(v.begin(), v.end(), cmp);
		for (auto it : v) {
			cout << it.first << " ";
		}
		cout << endl;
	}
	return 0;
}

