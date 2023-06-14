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
		multiset<int, greater<int>> tang1;
		multiset<int> tang2;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			tang2.insert(a[i]);
		}
		vector<int> res;
		for (int i = 0; i < n; i++) {
			tang1.insert(a[i]);
			tang2.erase(tang2.find(a[i]));
			if (!tang2.empty() && *tang1.begin() <= *tang2.begin()) {
				res.push_back(i);
			}
		}
		if (res.size() == 0) {
			cout << "0" << endl;
			cout << endl;
		} 
		else {
			cout << res.size() << endl;
			for (int x : res) cout << x + 1 << " ";
			cout << endl;
		}
	}
	return 0;
}