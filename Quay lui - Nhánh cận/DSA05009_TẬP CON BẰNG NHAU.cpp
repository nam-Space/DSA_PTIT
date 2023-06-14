#include <bits/stdc++.h>
using namespace std;

int n, a[1001], sum, check;

void Try(int i, int k) {
	if (check) return;
	for (int j = i; j <= n; j++) {
		if (check) return;
		if (k + a[j] == sum && !check) {
			check = 1;
			cout << "YES" << endl;
		}
		else if (k + a[j] < sum) {
			Try(i + 1, k + a[j]);
		}
	}
}

int main(){
    int t;
    cin >> t;
    while(t--) {
    	cin >> n;
    	sum = 0, check = 0;
    	for (int i = 1; i <= n; i++) {
    		cin >> a[i];
    		sum += a[i];
		}
		if (sum % 2 == 1) cout << "NO" << endl;
		else {
			sum /= 2;
			Try(1, 0);
		}
	}
}
