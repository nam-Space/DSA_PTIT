#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

char a[1001];
int x[1001];
int n, k;

void nhap() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		a[i] = i + 64;
	} 
	for (int i = 1; i <= n; i++) {
		x[i] = i;
	} 
}

void in() {
	for (int i = 1; i <= k; i++) {
		cout << a[x[i]];
	}
	cout << endl;
}

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		if (i == k) in();
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
