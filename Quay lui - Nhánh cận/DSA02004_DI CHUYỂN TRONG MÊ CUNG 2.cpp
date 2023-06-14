#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int n;
bool visited[1001][1001];
vector<string> res;
int a[1001][1001];

void nhap() {
	res.clear();
	memset(visited, false, sizeof(visited));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}

void Try(int i, int j, string s) {
	if (i == n && j == n) {
		res.push_back(s);
		return;
	}
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && !visited[i1][j1] && a[i1][j1] == 1) {
			if (k == 0) {
				visited[i1][j1] = true;
				Try(i1, j1, s + "D");
				visited[i1][j1] = false;
			}
			else if (k == 1) {
				visited[i1][j1] = true;
				Try(i1, j1, s + "R");
				visited[i1][j1] = false;
			}
			else if (k == 2) {
				visited[i1][j1] = true;
				Try(i1, j1, s + "L");
				visited[i1][j1] = false;
			}
			else {
				visited[i1][j1] = true;
				Try(i1, j1, s + "U");
				visited[i1][j1] = false;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		if (a[1][1] == 1) {
			visited[1][1] = true;
			Try(1, 1, "");
			visited[1][1] = false;
		}
		if (res.size() == 0) cout << "-1" << endl;
		else {
			sort(res.begin(), res.end());
			for (string s : res) cout << s << " ";
			cout << endl;
		}
	}
	return 0;
}



