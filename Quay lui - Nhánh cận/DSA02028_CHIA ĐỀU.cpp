#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

int n, k, res, a[10001];

void Try(int i, int collect, int sum, int cnt) {
	if (i == n + 1 && cnt == k) {
		res++;
		return;
	}
	for (int j = i; j <= n; j++) {
		collect += a[j];
		if (collect == sum) {
			Try(j + 1, 0, sum, cnt + 1);
		}
	}
}

int main(){
    int t; 
	t = 1;
    while(t--){
    	res = 0;
    	int sum = 0;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum % k != 0) {
			cout << 0 << endl;
		}
		else {
			Try(1, 0, sum / k, 0);
    		cout << res << endl;
		}
    }
}
