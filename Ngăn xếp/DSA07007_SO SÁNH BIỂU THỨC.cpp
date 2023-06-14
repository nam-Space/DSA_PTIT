#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

string xoa_ngoac(string s) {
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')') {
			int index = st.top(); st.pop();
			if (s[index - 1] == '-') {
				for (int j = index + 1; j < i; j++) {
					if (s[j] == '+') s[j] = '-';
					else if (s[j] == '-') s[j] = '+';
				}
			}
		}
	}
	string res = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '(' && s[i] != ')') res += s[i];
	} 
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		s1 = xoa_ngoac(s1);
		s2 = xoa_ngoac(s2);
		if (s1 == s2) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
}

