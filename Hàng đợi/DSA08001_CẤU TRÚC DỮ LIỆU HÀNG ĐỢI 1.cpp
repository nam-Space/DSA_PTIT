#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		queue<int> q;
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			int opt;
			cin >> opt;
			if (opt == 1) {
				cout << q.size() << endl;
			}
			else if(opt == 2) {
				if (q.empty()) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else if(opt == 3) {
				int tmp;
				cin >> tmp;
				q.push(tmp);
			}
			else if(opt == 4) {
				if (!q.empty()) q.pop();
			}
			else if(opt == 5) {
				if (!q.empty()) cout << q.front() << endl;
				else cout << "-1" << endl;
			}
			else {
				if (!q.empty()) cout << q.back() << endl;
				else cout << "-1" << endl;
			}
		}
	}
}
