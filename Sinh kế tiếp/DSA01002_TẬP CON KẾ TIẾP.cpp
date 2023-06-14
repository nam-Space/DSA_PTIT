#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n, k;

void nhap() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
}

void sinh() {
	int i = k;
	while(a[i] == n - k + i && i >= 1) {
		i--;
	}
	if (i == 0) {
		for (int j = 1; j <= k; j++) {
			a[j] = j;
		}
	}
	else {
		a[i]++;
		for (int j = i + 1; j <= k; j++) {
			a[j] = a[j - 1] + 1;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		sinh();
		for (int i = 1; i <= k; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
