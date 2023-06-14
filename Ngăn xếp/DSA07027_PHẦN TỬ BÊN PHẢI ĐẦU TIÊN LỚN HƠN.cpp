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
		int a[n], b[n];
		for (int &x : a) cin >> x;
		stack<int> st;
		for (int i = n - 1; i >= 0; i--) {
			while(!st.empty() && a[i] >= a[st.top()]) st.pop();
			b[i] = st.empty() ? -1 : a[st.top()];
			st.push(i);
		}
		for (int x : b) cout << x << " ";
		cout << endl;
	}  
}

