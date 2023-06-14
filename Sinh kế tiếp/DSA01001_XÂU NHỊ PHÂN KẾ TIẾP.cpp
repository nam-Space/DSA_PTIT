#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[1001];
int n;

void sinh() {
	int i = n;
	while(a[i] == 1 && i >= 1) {
		a[i] = 0;
		i--;
	}
	if (i == 0) return;
	a[i] = 1;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		memset(a, 0, sizeof(a));
		string s;
		cin >> s;
		n = s.size();
		for (int i = 1; i <= n; i++) {
			a[i] = s[i - 1] - '0';
		}
		sinh();
		for (int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << endl;
	}
}
