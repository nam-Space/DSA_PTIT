#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    t = 1;
    while(t--) {
    	int a, b;
    	cin >> a >> b;
    	string s1 = to_string(a);
    	string s2 = to_string(b);
    	for (int i = 0; i < s1.size(); i++) {
    		if (s1[i] == '6') s1[i] = '5';
		}
		for (int i = 0; i < s2.size(); i++) {
    		if (s2[i] == '6') s2[i] = '5';
		}
		cout << stoi(s1) + stoi(s2) << " ";
		for (int i = 0; i < s1.size(); i++) {
    		if (s1[i] == '5') s1[i] = '6';
		}
		for (int i = 0; i < s2.size(); i++) {
    		if (s2[i] == '5') s2[i] = '6';
		}
		cout << stoi(s1) + stoi(s2) << endl;
	}
}


