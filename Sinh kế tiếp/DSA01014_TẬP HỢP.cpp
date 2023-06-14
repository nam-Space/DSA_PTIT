#include <bits/stdc++.h>
using namespace std;

int n, k, s, cnt;
int a[101];

bool check() {
	int sum = 0;
	for (int i = 1; i <= k; i++) {
		sum += a[i];
	}
	return sum == s;
}

void Try(int i) {
	for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if (i == k) {
			if(check()) cnt++;
		}
		else Try(i + 1);
	}
}

int main() {
	while(cin >> n && cin >> k && cin >> s) {
		if (n == 0 && k == 0 && s == 0) return 0;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = i;
		}
		Try(1);
		cout << cnt << endl;
	}
	return 0;
}
