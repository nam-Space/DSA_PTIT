#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

char a[101];
int x[101];
char c;
int n, m, k, used[101];
vector<string> res;

void nhap() {
	cin >> c;
	n = c - 64;
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; i++) {
		a[i] = i + 64;
		x[i] = i;
	}
} 

void in() {
	for (int i = 1; i <= n; i++) {
		cout << a[x[i]];
	}
	cout << endl;
}

bool check() {
	for (int i = 2; i <= n - 1; i++) {
		if (a[x[i]] == 'E' || a[x[i]] == 'A') {
			if (a[x[i - 1]] != 'E' && a[x[i + 1]] != 'E' && a[x[i - 1]] != 'A' && a[x[i + 1]] != 'A') {
				return false;
			}
		}
	}
	return true;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			x[i] = j;
			used[j] = 1;
			if (i == n) {
				if (check()) in();
			}
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

