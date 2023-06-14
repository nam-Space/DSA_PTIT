#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool nhoNhat(int s, int n) {
	stack<int> st;
	while(s > 0) {
		if (s >= 9) {
			st.push(9);
			s -= 9;
			n--;
		}
		else {
			st.push(s);
			s = 0;
			n--;
		}
	}
	if (n < 0) return false;
	if (n > 0) {
		int so = st.top(); st.pop();
		st.push(so - 1);
		while(n > 1) {
			st.push(0);
			n--;
		}
		st.push(1);
		n--;
	}
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << " ";
	return true;
}

bool lonNhat(int s, int n) {
	stack<int> st;
	while(s > 0) {
		if (s >= 9) {
			st.push(9);
			s -= 9;
			n--;
		}
		else {
			st.push(s);
			s = 0;
			n--;
		}
	}
	if (n < 0) return false;
	while(n > 0) {
		st.push(0);
		n--;
	}
	vector<int> res;
	while(!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}
	reverse(res.begin(), res.end());
	for (int x : res) cout << x;
	return true;
}

int main(){
	int t;
	t = 1;
	while(t--) {
		int n, s;
		cin >> n >> s;
		if (s == 0 || !nhoNhat(s, n) || !lonNhat(s, n)) cout << "-1 -1" << endl;
	} 
}

