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

void prev() {
	int i = k;
	while(i >= 1 && a[i - 1] + 1 == a[i]) {
		i--;
	}
	if (i == 0) {
		for (int j = 1; j <= k; j++) {
			a[j] = j + k - 1;
		}
	}
	else {
		a[i]--;
		for (int j = i + 1; j <= k; j++) {
			a[j] = n - k + j;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		prev();
		for (int i = 1; i <= k; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}

