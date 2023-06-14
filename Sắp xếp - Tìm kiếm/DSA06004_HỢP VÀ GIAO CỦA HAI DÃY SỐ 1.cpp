#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n, m;
    	cin >> n >> m;
    	set<int> se1, se2, se3;
    	for (int i = 0; i < n; i++) {
    		int x; cin >> x;
    		se1.insert(x);
    		se3.insert(x);
		}
		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			se2.insert(x);
			se3.insert(x);
		}
		for (int x : se3) {
			cout << x << " ";
		}
		cout << endl;
		for (int x : se2) {
			if (se1.find(x) != se1.end()) {
				cout << x << " ";
			}
		}
		cout << endl;
	}
}
