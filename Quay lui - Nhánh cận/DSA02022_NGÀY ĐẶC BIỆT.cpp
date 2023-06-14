#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[101], x[101];
int n, m, k, used[10001];
string s;
int cnt;

void nhap() {
	cnt = 0;
	n = 8;
	memset(a, 0, sizeof(a));
}

bool check() {
	if (a[1] == 0 && a[2] == 0) return false;
	if (a[3] == 0 && a[4] == 0) return false;
	if (a[3] == 2) return false;
	if (a[5] == 0) return false;
	return true;
}

void in() {
	cout << a[1] << a[2] << "/" << a[3] << a[4] << "/" << a[5] << a[6] << a[7] << a[8] << endl;
}

void Try(int i) {
	for (int j = 0; j <= 2; j += 2) {
		a[i] = j;
		if (i == n) {
			if (check()) in();
		}
		else Try(i + 1);
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

