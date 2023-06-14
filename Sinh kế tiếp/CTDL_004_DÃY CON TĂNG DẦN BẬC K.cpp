#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k, cnt;
int a[101], x[101];

void nhap() {
	cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		x[i] = i;
	}
}

bool check() {
	vector<int> v1;
	vector<int> v2;
	for (int i = 1; i <= k; i++) {
		v1.push_back(a[x[i]]);
		v2.push_back(a[x[i]]);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) {
			if (check()) cnt++;
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
    	cout << cnt << endl;
	}
}

