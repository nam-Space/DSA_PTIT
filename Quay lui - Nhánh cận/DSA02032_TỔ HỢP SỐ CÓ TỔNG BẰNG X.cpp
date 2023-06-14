#include <bits/stdc++.h> 
using namespace std;

int n, k;
int a[101];
vector<vector<int>> res;

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
		res.clear();
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		vector<int> v;
		Try(1, 0, v);
		if (res.size() == 0) {
			cout << "-1" << endl;
			continue;
		}
		sort(res.begin(), res.end());
		for (vector<int> v : res) {
			string s = "[";
			for (int x : v) {
				s += to_string(x) + " ";
			}
			s = s.substr(0, s.size() - 1);
			s += "]";
			cout << s;
		}
		cout << endl;
	}
	return 0;
}



