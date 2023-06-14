#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[101], x[101];
int n, k, used[10001];
string s;
vector<vector<int>> res;

void nhap() {
	res.clear();
	memset(x, 0, sizeof(x));
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
}

bool check() {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) sum += a[i];
	}
	return sum == k;
}

void process() {
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (x[i] == 1) v.push_back(a[i]);
	}
	res.push_back(v);
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n) {
			if(check()) process();
		}
		else Try(i + 1);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		sort(res.begin(), res.end());
		if (res.size() == 0) {
			cout << "-1" << endl;
		}
		else {
			for (vector<int> v : res) {
				cout << "[";
				for (int i = 0; i < v.size() - 1; i++) {
					cout << v[i] << " ";
				}
				cout << v[v.size() - 1] << "] ";
			}
			cout << endl;
		}
	}
}
