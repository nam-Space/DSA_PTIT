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
		for (int i = 0; i < s.size(); i++) {
			if (isdigit(s[i])) {
				if (i < s.size() - 1) {
					if (isdigit(s[i + 1])) res += string(1, s[i]);
					else res += string(1, s[i]) + " ";
				}
				else res += string(1, s[i]);
			}
			else if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')') {
				while(!st.empty() && st.top() != '(') {
					res += " " + string(1, st.top()) + " ";
					st.pop();
				}
				st.pop();
			}
			else {
				while(!st.empty() && degree(st.top()) >= degree(s[i])) {
					res += " " + string(1, st.top()) + " ";
					st.pop();
				}
				st.push(s[i]);
			}
		}
		while(!st.empty()) {
			if (st.top() != '(') res += " " + string(1, st.top()) + " ";
			st.pop();
		}
		stringstream ss(res);
		string tmp;
		vector<string> v;
		while(ss >> tmp) {
			v.push_back(tmp);
		}
		stack<string> st2;
		ll ans = 0;
		for (string x : v) {
			if (x == "+" || x == "-" || x == "*" || x == "/") {
				string a = st2.top(); st2.pop();
				string b = st2.top(); st2.pop();
				ll tmp;
				if (x == "+") tmp = stoll(b) + stoll(a);
				else if (x == "-") tmp = stoll(b) - stoll(a);
				else if (x == "*") tmp = stoll(b) * stoll(a);
				else tmp = stoll(b) / stoll(a);
				st2.push(to_string(tmp));
			}
			else st2.push(x);
		}
		cout << st2.top() << endl;
	}
}

