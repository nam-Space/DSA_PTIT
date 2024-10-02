#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int open = 0, close = 0;
		for (char x : s) {
			if (x == '(') open++;
			else if (x == ')') close++;
		}
		int r = abs(close - open);
		stack<string> st;
		if (open > close) {
			for (char x : s) {
				if (x == '(' && r > 0) {
					st.push("1-");
					r--;
				}
				else if (x == '(' && r == 0) {
					st.push("0");
				}
				else if (x == ')') {
					st.push("1");
				}
				else {
					st.push(x + (string)"");
				}
			}
			string res = "";
			while(!st.empty()) {
				res += st.top() ;
				st.pop();
			}
			reverse(res.begin(), res.end());
			cout << res << endl;
		}
		else {
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] == ')' && r > 0) {
					st.push("-1");
					r--;
				}
				else if (s[i] == ')' && r == 0) {
					st.push("1");
				}
				else if (s[i] == '(') {
					st.push("0");
				}
				else {
					st.push(s[i] + (string)"");
				}
			}
			string res = "";
			while(!st.empty()) {
				res += st.top() ;
				st.pop();
			}
			cout << res << endl;
		}
	}
	return 0;
}