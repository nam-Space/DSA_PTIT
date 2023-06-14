#include <bits/stdc++.h>
using namespace std;

int n, w, fopt = INT_MIN;
int a[101], c[101], x[101], xopt[101];
bool chuaxet[101];

void nhap() {
	memset(chuaxet, true, sizeof(chuaxet));
	memset(xopt, 0, sizeof(xopt));
	cin >> n >> w;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
}
void Try(int i, int sum_val, int sum_weight) {
	if (sum_weight > w) {
		return;
	}
	if (fopt < sum_val) {
		fopt = sum_val;
		memset(xopt, 0, sizeof(xopt));
		for (int j = 1; j <= n; j++) {
			if (x[j] > 0) xopt[x[j]] = 1;
		}
	}
	for (int j = 1; j <= n; j++) {
		if (chuaxet[j]) {
			x[i] = j;
			chuaxet[x[i]] = false;
			sum_val += c[x[i]];
			sum_weight += a[x[i]];
			if (i == n) {
				break;
			}
			else Try(i + 1, sum_val, sum_weight);
			chuaxet[x[i]] = true;
			sum_val -= c[x[i]];
			sum_weight -= a[x[i]];
		}
	}
}

int main() {
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(1, 0, 0);
		cout << fopt << endl;
		for (int i = 1; i <= n; i++) {
			cout << xopt[i] << " ";
		}
		cout << endl;
	}
    return 0;
}

