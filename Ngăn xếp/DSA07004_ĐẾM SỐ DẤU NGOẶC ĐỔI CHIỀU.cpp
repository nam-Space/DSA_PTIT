#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int cnt(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (st.empty() || s[i] == '(') st.push(s[i]);
		else {
			if (st.top() == '(') st.pop();
			else st.push(s[i]);
		}
	}
	int d1 = 0, d2 = 0;
	while(!st.empty()) {
		if (st.top() == '(') d1++;
		else d2++;
		st.pop();
	}
	int res = d1 / 2 + d2 / 2 + d1 % 2 + d2 % 2;
	return res;
}
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << cnt(s) << endl;
	}
	return 0;
}



