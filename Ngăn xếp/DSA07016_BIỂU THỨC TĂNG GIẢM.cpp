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
		for (int i = 0; i <= s.size(); i++) {
			if (s[i] == 'D') st.push(i + 1);
			else {
				st.push(i + 1);
				while(!st.empty()) {
					cout << st.top();
					st.pop();
				}
			}
		}
		while(!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << endl;
	} 
}

