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
		stack<string> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				string a = st.top(); st.pop();
				string b = st.top(); st.pop();
				string res = b + s[i] + a;
				st.push(res);
			}
			else st.push(string(1, s[i]));
		} 
		cout << st.top() << endl;
	}
	return 0;
}
