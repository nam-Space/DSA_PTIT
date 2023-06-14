#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int n, k;
	cin >> n;
	int a[n];
	for (int &x : a) cin >> x;
	cin >> k;
	for (int i = 0; i < n; i++) {
		if (a[i] == k) continue;
		cout << a[i] << " ";
	}
}
