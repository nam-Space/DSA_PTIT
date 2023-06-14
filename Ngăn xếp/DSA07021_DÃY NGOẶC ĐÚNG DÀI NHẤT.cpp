#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int dem(string s) {
	int res = 0;
	stack<int> st;
	st.push(-1);
	for (int i = 0; i < s.size(); i++) {
		if (st.empty()) st.push(i);
		else if (s[i] == '(') st.push(i);
		else {
			st.pop();
			if (!st.empty()) res = max(res, i - st.top());
			else st.push(i);
		}
	}
	return res;
}
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << dem(s) << endl;
	}
	return 0;
}



