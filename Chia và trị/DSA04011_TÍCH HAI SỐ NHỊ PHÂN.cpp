#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, m;
int a[31], b[31];

ll thap_phan(int a[], int n) {
	int k = 0;
	ll res = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] == 1) {
			res += pow(2, k);
		}
		k++;
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		n = s1.size(), m = s2.size();
		for (int i = 1; i <= n; i++) {
			a[i] = s1[i - 1] - '0';
		}
		for (int i = 1; i <= n; i++) {
			b[i] = s2[i - 1] - '0';
		}
		ll so1 = thap_phan(a, n);
		ll so2 = thap_phan(b, m);
		cout << so1 * so2 << endl;
	}
	return 0;
}

