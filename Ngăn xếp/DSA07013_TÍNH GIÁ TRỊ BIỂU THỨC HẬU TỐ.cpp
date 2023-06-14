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
				int res;
				if (x == '+') res = stoi(b) + stoi(a);
				else if (x == '-') res = stoi(b) - stoi(a);
				else if (x == '*') res = stoi(b) * stoi(a);
				else res = stoi(b) / stoi(a);
				st.push(to_string(res));
			}
			else st.push(string(1, x));
		}
		cout << st.top() << endl;
	} 
}

