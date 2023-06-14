#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int cnt[300];
		memset(cnt, 0, sizeof(cnt));
		for (char x : s) {
			cnt[x]++;
		}
		int max_ele = *max_element(cnt, cnt + 300);
		if (s.size() - max_ele >= max_ele - 1) cout << "1" << endl;
		else cout << "-1" << endl;
	} 
}

