#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

bool cmp(int a, int b) {
	return a > b;
}

int main(){
	int t;
	t = 1;
	while(t--) {
		int n;
		cin >> n;
		vector<int> chan, le;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			if (i % 2 == 0) chan.push_back(x);
			else le.push_back(x);
		}
		sort(chan.begin(), chan.end(), cmp);
		sort(le.begin(), le.end());
		int i = 0, j = 0;
		while(i < le.size() && j < chan.size()) {
			cout << le[i++] << " " << chan[j++] << " ";
		}
		while(i < le.size()) {
			cout << le[i++] << " ";
		}
		while(j < chan.size()) {
			cout << chan[j++] << " ";
		}
		cout << endl;
	}
	return 0;
}

