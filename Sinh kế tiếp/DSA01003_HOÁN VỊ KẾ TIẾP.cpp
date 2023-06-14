#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n;

void nhap() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void sinh() {
	int i = n - 1;
	while(a[i] > a[i + 1]) {
		i--;
	}
	if (i == 0) {
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
	}
	else {
		int j = n;
		while(a[i] > a[j]) {
			j--;
		}
		swap(a[i], a[j]);
		reverse(a + i + 1, a + n + 1);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		sinh();
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
