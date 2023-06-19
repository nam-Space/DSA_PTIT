#include <bits/stdc++.h>
using namespace std;

int n, res, cnt;
string st, en;
set<string> se;

struct Data {
	int index, cnt;
};

void nhap() {
	se.clear();
	res = 1e9;
	cin >> n >> st >> en;
	for (int i = 0; i < n; i++) {
		string x; cin >> x;
		if (x != st) se.insert(x);
	}
}

void bfs() {
	queue<pair<string, int>> q;
	q.push({st, 1});
	while(!q.empty()) {
		pair<string, int> v = q.front(); q.pop();
		string tmp = v.first;
		if (tmp == en) res = min(res, v.second);
		for (int i = 0; i < tmp.size(); i++) {
			char c = tmp[i];
			for (int j = 'A'; j <= 'Z'; j++) {
				tmp[i] = j;
				if (se.find(tmp) != se.end()) {
					q.push({tmp, v.second + 1});
					se.erase(tmp);
				}
			}
			tmp[i] = c;
		}
	}
}

int main(){
	int test; 
	cin >> test;
	while(test--){
		nhap();
		bfs();
		cout << res << endl;
	}
	return 0;
}