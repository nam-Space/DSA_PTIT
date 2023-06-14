#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int test;
    	cin >> test;
    	string s;
    	cin >> s;
    	if (next_permutation(s.begin(), s.end())) {
    		cout << test << " " << s << endl;
		}
		else cout << test << " " << "BIGGEST" << endl;
	}
}

