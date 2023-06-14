#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n, s, m;
    	cin >> n >> s >> m;
    	if (n * (s - s / 7) >= s * m) {
    		int i = 1;
    		while(n * i < s * m) {
    			i++;
			}
			cout << i << endl;
		}
		else cout << "-1" << endl;
	}
}


