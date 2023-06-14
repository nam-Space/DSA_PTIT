#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> action;
		int a[n], b[n];
		for (int &x : a) {
			cin >> x;
		}
		for (int &x : b) {
			cin >> x;
		}
		for (int i = 0; i < n; i++) {
			action.push_back({a[i], b[i]});
		}
		sort(action.begin(), action.end(), cmp);
		int cnt = 1, index = 0;
		for (int i = 1; i < n; i++) {
			if (action[index].second <= action[i].first) {
				cnt++;
				index = i;
			}
		}
		cout << cnt << endl;
	} 
}

