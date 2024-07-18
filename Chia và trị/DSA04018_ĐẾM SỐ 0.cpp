#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

void nhap(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main(){
	int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int a[n];
    	nhap(a, n);
    	auto it = lower_bound(a, a + n, 1);
    	int p = it - a; // vi tri dau tien a[i] = 1
    	if (p == n) { // neu ko tim thay a[i] = 1 -> full 0
    		cout << n << endl;
		}
		else { // tim thay a[i] = 1
			p--;
			cout << p + 1 << endl;
		}
    }
    return 0;
}
