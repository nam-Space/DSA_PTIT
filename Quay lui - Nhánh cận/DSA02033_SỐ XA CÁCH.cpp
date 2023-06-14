#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[101];
int x[101];
char c;
int n, m, k, used[101];
vector<string> res;

void nhap() {
	memset(used, 0, sizeof(used));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
} 

void in() {
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
}

bool check() {
	for (int i = 1; i <= n - 1; i++) {
		if (abs(a[i + 1] - a[i]) == 1) return false;
	}
	return true;
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!used[j]) {
			a[i] = j;
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
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
	} 
}

