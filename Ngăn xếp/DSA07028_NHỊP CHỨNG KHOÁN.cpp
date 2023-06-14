#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1], b[n + 1];
		for (int i = 1; i <= n; i++) cin >> a[i];
		stack<int> st;
		for (int i = 1; i <= n; i++) {
			while(!st.empty() && a[i] >= a[st.top()]) st.pop();
			b[i] = st.empty() ? 0 : st.top();
			st.push(i);
		}
		for (int i = 1; i <= n; i++) {
			cout << i - b[i] << " ";
		}
		cout << endl;
	}
	return 0;
}



