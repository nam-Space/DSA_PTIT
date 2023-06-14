#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n, k;

void nhap() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = n - i + 1;
	}
}
int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		do {
			for (int i = 1; i <= n; i++) {
				cout << a[i];
			}
			cout << " ";
		} while(prev_permutation(a + 1, a + n + 1));
		cout << endl;
	}
}
