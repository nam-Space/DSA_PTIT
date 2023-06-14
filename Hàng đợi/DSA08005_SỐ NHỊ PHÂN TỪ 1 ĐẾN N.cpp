#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			stack<int> st;
			int tmp = i;
			while(tmp) {
				st.push(tmp % 2);
				tmp = tmp / 2;
			}
			while(!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << " ";
		}
		cout << endl;
	} 
}

