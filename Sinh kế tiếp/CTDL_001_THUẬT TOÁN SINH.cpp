#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;
int n, ok, a[101];

void ktao() {
	ok = 0;
	memset(a, 0, sizeof(a));
}

void sinh() {
	int i = n;
	while(a[i] == 1 && i >= 1) {
		a[i] = 0;
		i--;
	}
	if (i == 0) ok = 1;
	else {
		a[i] = 1;
	}
}

bool check() {
	int l = 1, r = n;
	while(l < r) {
		if (a[l] != a[r]) return false;
		l++;
		r--; 
	} 
	return true;
}

int main(){
	cin >> n;
	while(!ok) {
		if (check()) {
			for (int i = 1; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
		sinh();
	}
}
