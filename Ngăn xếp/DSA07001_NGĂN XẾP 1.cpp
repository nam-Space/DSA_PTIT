#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int n;
	stack<int> st;
	while(cin >> s) {
		if (s == "push") {
			cin >> n;
			st.push(n);
		}
		else if(s == "pop") {
			st.pop();
		}
		else if (s == "show") {
			vector<int> v;
			if (st.empty()) {
				cout << "empty" << endl;
				continue;
			}
			while(!st.empty()) {
				int x = st.top();
				st.pop();
				v.push_back(x);
			}
			reverse(v.begin(), v.end());
			for (int x : v) cout << x << " ";
			cout << endl;
			for (int x : v) st.push(x);
		}
	}
    return 0;
}
