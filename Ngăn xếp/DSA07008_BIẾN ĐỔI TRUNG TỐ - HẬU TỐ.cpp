#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int degree(char x) {
	if (x == '^') return 3;
	if (x == '*' || x == '/') return 2;
	if (x == '+' || x == '-') return 1;
	return 0;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		stack<char> st;
		string res = "";
		for (char x : s) {
			if (isalpha(x)) res += x;
			else if (x == '(') st.push(x);
			else if (x == ')') {
				while(!st.empty() && st.top() != '(') {
					res += st.top();
					st.pop();
				}
				st.pop();
			}
			else {
				while(!st.empty() && degree(st.top()) >= degree(x)) {
					res += st.top();
					st.pop();
				}
				st.push(x);
			}
		}
		while(!st.empty()) {
			if (st.top() != '(') res += st.top();
			st.pop();
		}
		cout << res << endl;
	}  
}

