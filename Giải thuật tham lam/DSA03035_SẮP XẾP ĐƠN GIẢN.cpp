#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    t = 1;
    while(t--) {
    	int n;
    	cin >> n;
    	int index[n + 1];
    	for (int i = 1; i <= n; i++) {
    		int x; cin >> x;
    		index[x] = i;
		}
		int res = INT_MAX;
		int dem = 1;
		int i = index[1];
		for (int j = 2; j <= n; j++) {
			if (index[j] > i) dem++;
			else dem = 1;
			i = index[j];
			res = min(res, n - dem);
		}
		cout << res << endl;
	}
}


