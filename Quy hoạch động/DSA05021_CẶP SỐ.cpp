#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<pair<int, int>> v;
    	for (int i = 0; i < n; i++) {
    		int x, y; cin >> x >> y;
    		v.push_back({x, y});
		}
		sort(v.begin(), v.end(), cmp);
		vector<int> dp(n, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (v[i].first > v[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
}


