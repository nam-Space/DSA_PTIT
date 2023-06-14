#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 123456789;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for (int &x : a) cin >> x;
		int sum1 = 0, sum2 = INT_MIN;
		for (int i = 0; i < n; i++) {
			sum1 += a[i];
			sum2 = max(sum2, sum1);
			if (sum1 < 0) sum1 = 0;
		}
		cout << sum2 << endl;
	} 
	return 0;
}

