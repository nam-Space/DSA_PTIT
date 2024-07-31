#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

struct Data {
	int start, end;
};

vector<Data> a;
int n, x[201];
string s;
set<string> res;

bool cmp(Data x, Data y) {
	return x.start < y.start;
}

void process() {
	int cnt = 0;
	bool visited[201];
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			if (x[cnt] == 0) {
				visited[a[cnt].start] = visited[a[cnt].end] = true;
			}
			cnt++;
		}
	}
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (!visited[i]) {
			tmp += s[i];
		}
	}
	res.insert(tmp);
}

void Try(int i) {
	for (int j = 0; j <= 1; j++) {
		x[i] = j;
		if (i == n - 1) process();
		else Try(i + 1);
	}
}

int main(){
	int t;
	t = 1;
	while(t--) {
		a.clear();
		res.clear();
		memset(x, 0, sizeof(x));
		cin >> s;
		stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push(i);
			}
			else if (s[i] == ')') {
				a.push_back({st.top(), i});
				st.pop();
			}
		}
		
		sort(a.begin(), a.end(), cmp);
		n = a.size();
		Try(0);
		for (string x : res) {
			if (x != s) {
				cout << x << endl;
			}
		}
	}
	return 0;
}
