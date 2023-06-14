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
		for (char x : s) {
			if (x == '+' || x == '-' || x == '*' || x == '/') {
				string a = st.top(); st.pop();
				string b = st.top(); st.pop();
				string res = x + b + a;
				st.push(res);
			}
			else st.push(string(1, x));
		}
		cout << st.top() << endl;
	}  
}

