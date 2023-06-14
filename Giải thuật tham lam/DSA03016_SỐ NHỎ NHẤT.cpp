#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int s, d;
    	cin >> s >> d;
    	stack<int> st;
    	while(s > 0) {
    		if (s >= 9) {
    			st.push(9);
    			s -= 9;
    			d--;
			}
			else {
				st.push(s);
				s = 0;
				d--;
			}
		}
		if (d < 0) {
			cout << "-1" << endl;
			continue;
		}
		if (d > 0) {
			int so = st.top(); st.pop();
			st.push(so - 1);
			while(d > 1) {
				st.push(0);
				d--;
			}
			st.push(1);
			d--;
		}
		while(!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}


