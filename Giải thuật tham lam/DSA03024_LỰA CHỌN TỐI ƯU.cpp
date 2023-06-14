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
    	vector<pair<int, int>> jobs;
    	for (int i = 0; i < n; i++) {
    		int x, y; cin >> x >> y;
    		jobs.push_back({x, y});
		}
		sort(jobs.begin(), jobs.end(), cmp);
		int cnt = 1, index = 0;
		for (int i = 1; i < n; i++) {
			if (jobs[index].second <= jobs[i].first) {
				cnt++;
				index = i;
			}
		}
		cout << cnt << endl;
	}
}


