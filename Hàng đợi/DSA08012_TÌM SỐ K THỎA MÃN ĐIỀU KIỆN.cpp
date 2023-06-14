#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<int> res;
int l, r;

bool check(int x) {
	string s = to_string(x);
	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++) {
			if (s[i] == s[j]) return false;
		}
	}
	return true;
}

int bfs(int l, int r) {
	queue<string> q;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	res.push_back(1);
	res.push_back(2);
	res.push_back(3);
	res.push_back(4);
	res.push_back(5);
	while(1) {
		string top = q.front(); q.pop();
		if (top.size() == 6) break;
		q.push(top + "0");
		q.push(top + "1");
		q.push(top + "2");
		q.push(top + "3");
		q.push(top + "4");
		q.push(top + "5");
		res.push_back(stoi(top + "0"));
		res.push_back(stoi(top + "1"));
		res.push_back(stoi(top + "2"));
		res.push_back(stoi(top + "3"));
		res.push_back(stoi(top + "4"));
		res.push_back(stoi(top + "5"));
	}
	int cnt = 0;
	for (int x : res) {
		if (x >= l && x <= r) {
			if (check(x)) cnt++;
		}
	}
	return cnt;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		res.clear();
		cin >> l >> r;
		cout << bfs(l, r) << endl;
	}
}
