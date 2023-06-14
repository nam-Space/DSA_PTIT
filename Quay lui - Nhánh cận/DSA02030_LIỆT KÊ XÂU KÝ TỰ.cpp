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
	cin >> c >> k;
	n = c - 64;
	for (int i = 1; i <= n; i++) {
		a[i] = i + 64;
	}
	x[0] = 1;
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
	for (int j = x[i - 1]; j <= n; j++) {
		x[i] = j;
		if (i == k) in();
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

