#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		stack<string> st;
		stringstream ss(s);
		string tmp;
		while(ss >> tmp) {
			st.push(tmp);
		}
		while(!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	} 
}

