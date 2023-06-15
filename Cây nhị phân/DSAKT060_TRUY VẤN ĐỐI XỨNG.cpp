#include <bits/stdc++.h>
using namespace std;

bool xauDoiXung(string s, int l, int r) {
	while(l <= r) {
		if (s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

int main(){
	int t; 
	t = 1;
	while(t--){
		string s;
		cin >> s;
		s = "@" + s;
		int q;
		cin >> q;
		while(q--) {
			char c;
			int l, r;
			cin >> c >> l >> r;
			if (c == 'q') {
				if (xauDoiXung(s, l, r)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else {
				s[l] = r + '0';
			}
		}
	}
	return 0;
}


