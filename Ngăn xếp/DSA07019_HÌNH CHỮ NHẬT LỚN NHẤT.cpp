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
		int a[n];
		for (int &x : a) cin >> x;
		stack<int> st;
		int i = 0;
		ll res = 0;
		while(i < n) {
			if(st.empty() || (a[i] >= a[st.top()])){
				st.push(i);
				i++;
			}
			else {
				int index = st.top(); st.pop();
				if (!st.empty()) res = max(res, 1ll * a[index] * (i - st.top() - 1));
				else res = max(res, 1ll * a[index] * i);
			}
		}
		while(!st.empty()) {
			int index = st.top(); st.pop();
			if (!st.empty()) res = max(res, 1ll * a[index] * (i - st.top() - 1));
			else res = max(res, 1ll * a[index] * i);
		}
		cout << res << endl;
	} 
	return 0;
}



