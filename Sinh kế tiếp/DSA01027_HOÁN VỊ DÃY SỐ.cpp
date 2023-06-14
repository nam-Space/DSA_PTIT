#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[10001], x[10001];
int n, k, used[10001];

void nhap() {
	memset(used, 0, sizeof(used));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	}
}

void in() {
	for (int i = 1; i <= n; i++) {
		cout << a[x[i]] << " ";
	}
	cout << endl;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (used[j] == 0) {
			x[i] = j;
			used[j] = 1;
			if(i == n) in();
			else Try(i + 1);
			used[j] = 0;
		}
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1);
	}
}
