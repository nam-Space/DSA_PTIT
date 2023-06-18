#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];

int main(){
	int test; 
	cin >> test;
	while(test--){
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		int *a = new int[n];
		int *b = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		stack<int> st;
		for (int i = n - 1; i >= 0; i--) {
			while(!st.empty() && cnt[a[i]] >= cnt[a[st.top()]]) st.pop();
			b[i] = st.empty() ? -1 : a[st.top()];
			st.push(i);
		}
		for (int i = 0; i < n; i++) {
			cout << b[i] << " ";
		}
		cout << endl;
	}
	return 0;
}




