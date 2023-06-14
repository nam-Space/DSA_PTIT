#include <bits/stdc++.h>
using namespace std;

int a[101], b[101];
int n;

void nhap() {
	cin >> n;
	memset(a, 0, sizeof(a));
}

void ghiNhan() {
	for (int i = n; i >= 2; i--) {
		b[i] = (a[i] + a[i - 1]) % 2;
	} 
	b[1] = a[1];
	for (int i = 1; i <= n; i++) {
		cout << b[i];
	}
	cout << " ";
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		a[i] = j;
		if (i == n) {
			ghiNhan();
		}
		else Try(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		cout << endl;
	}
}
