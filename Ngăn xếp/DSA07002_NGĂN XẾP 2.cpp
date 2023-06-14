#include<bits/stdc++.h>
using namespace std;

int main() {
	stack<int> st;
	int q;
	cin >> q;
	while(q--) {
		string s;
		int n;
		cin >> s;
		if (s == "PUSH") {
			cin >> n;
			st.push(n);
		}
		else if(s == "PRINT") {
			if (st.empty()) {
				cout << "NONE" << endl;
			}
			else cout << st.top() << endl;
		}
		else if (s == "POP" && !st.empty()) {
			st.pop();
		}
	}
    return 0;
}
