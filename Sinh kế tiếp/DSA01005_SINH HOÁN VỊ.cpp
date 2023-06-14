#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001], used[1001];
int n, k;

void nhap() {
	memset(used, 0, sizeof(used));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
}

void in() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << " ";
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			used[j] = 1;
			a[i] = j;
			if (i == n) in();
			else Try(i + 1);
			used[j] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		cout << endl;
	}
}
