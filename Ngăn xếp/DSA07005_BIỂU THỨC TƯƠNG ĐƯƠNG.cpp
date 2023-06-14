#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
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
		cout << res << endl;
	} 
}

