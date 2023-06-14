#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int check(string s) {
	stack<int> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')') {
			int index = st.top(); st.pop();
			if (i - index == 2) return 1;
			if (s[index - 1] == '(' && s[i + 1] == ')') return 1;
		}
	}
	return 0;
}
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if (check(s)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}



