#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	set<int> se;
    	for (int i = 0; i < n; i++) {
    		string s;
    		cin >> s;
    		for (char x : s) {
    			se.insert(x - '0');
			}
		}
    	for (int x : se) {
    		cout << x << " ";
		}
		cout << endl;
	}
}
