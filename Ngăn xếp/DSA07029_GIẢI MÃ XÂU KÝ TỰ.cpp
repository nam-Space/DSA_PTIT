#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

string result(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ']') {
			st.push(s[i]);
		}
		else {
			string tmp = "";
			while(!st.empty() && st.top() != '[') {
				tmp = st.top() + tmp;
				st.pop();
			}
			st.pop();
			string number = "";
			while(!st.empty() && isdigit(st.top())) {
				number = st.top() + number;
				st.pop();
			}
			int num = 1;
			if (number.size() > 0) num = stoi(number);
			string x = "";
			for (int j = 1; j <= num; j++) {
				x += tmp;
			}
			for (int j = 0; j < x.size(); j++) {
				st.push(x[j]);
			}
		}
	}
	string res = "";
	while(!st.empty()) {
		res = st.top() + res;
		st.pop();
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << result(s) << endl;
	}
}
