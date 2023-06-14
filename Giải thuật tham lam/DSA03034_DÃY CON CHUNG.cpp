#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n, m, k; cin >> n >> m >> k;
    	int a[n], b[m], c[k];
    	for (int &x : a) cin >> x;
    	for (int &x : b) cin >> x;
		for (int &x : c) cin >> x;
		vector<int> res;
		int i = 0, j = 0, z = 0;
		while(i < n && j < m && z < k) {
			if (a[i] == b[j] && b[j] == c[z]) {
				res.push_back(a[i]);
				i++;
				j++;
				z++;
			}
			else if (a[i] <= b[j] && a[i] <= c[z]) i++;
			else if (b[j] <= a[i] && b[j] <= c[z]) j++;
			else z++;
		}
		if (res.size() == 0) cout << "NO" << endl;
		else {
			for (int x : res) cout << x << " ";
			cout << endl;
		}
	}
}


