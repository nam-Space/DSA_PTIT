#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int open = 0, close = 0, res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') open++;
			else close++;
			if (close > open) {
				for (int j = i + 1; j < s.size(); j++) {
					if (s[i] != s[j]) {
						res += j - i;
						swap(s[i], s[j]);
						open++;
						close--;
						break;
					}
				}
			}
		}
		cout << res << endl;
	} 
}

