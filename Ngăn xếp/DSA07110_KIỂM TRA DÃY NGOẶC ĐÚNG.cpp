#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

bool check(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
		else {
			if (s[i] == ')') {
				if (!st.empty() && st.top() == '(') st.pop();
			}
			else if (s[i] == ']') {
				if (!st.empty() && st.top() == '[') st.pop();
			}
			else if (s[i] == '}') {
				if (!st.empty() && st.top() == '{') st.pop();
			}
		}
	}
	return st.empty();
}
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if (check(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}



