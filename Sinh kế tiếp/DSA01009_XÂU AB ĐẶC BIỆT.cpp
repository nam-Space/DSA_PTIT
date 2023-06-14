#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k, cnt;
int a[101], x[101];
vector<string> res;

void nhap() {
	res.clear();
	cnt = 0;
	cin >> n >> k;
	memset(a, 0, sizeof(a));
}

bool check() {
	int cnt1 = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		int cnt2 = 0;
		for (int j = i; j <= i + k - 1; j++) {
			if (a[i] == a[j] && a[i] == 0) cnt2++;
		}
		if (cnt2 == k) cnt1++;
	}
	return cnt1 == 1;
}

void process() {
	string s = "";
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			s += "A";
		}
		else s += "B";
	}
	res.push_back(s);
	cnt++;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			if (check()) {
				process();
			}
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
    	sort(res.begin(), res.end());
    	for (string s : res) {
    		cout << s << endl;
		}
	}
}

