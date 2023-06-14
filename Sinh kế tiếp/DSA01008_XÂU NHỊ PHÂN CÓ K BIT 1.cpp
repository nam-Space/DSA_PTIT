#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n, k;

void nhap() {
	cin >> n >> k;
	memset(a, 0, sizeof(a));
}

void in() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) cnt++;
	}
	return cnt == k;
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			if (check()) in();
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
	}
}
