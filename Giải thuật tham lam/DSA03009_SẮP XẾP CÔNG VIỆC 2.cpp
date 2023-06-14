#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct Data {
	int id, dead, profit;
};

bool cmp(Data a, Data b) {
	return a.profit > b.profit;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<Data> jobs;
    	for (int i = 0; i < n; i++) {
    		int x, y, z;
    		cin >> x >> y >> z;
    		jobs.push_back({x, y, z});
		}
		sort(jobs.begin(), jobs.end(), cmp);
		int f[1001];
		memset(f, 0, sizeof(f));
		int cnt = 0, res = 0;
		for (int i = 0; i < n; i++) {
			while(f[jobs[i].dead] == 1 && jobs[i].dead >= 1) {
				jobs[i].dead--;
			}
			if (f[jobs[i].dead] == 0 && jobs[i].dead >= 1) {
				cnt++;
				f[jobs[i].dead] = 1;
				res += jobs[i].profit;
			}
		}
		cout << cnt << " " << res << endl;
	}
}


