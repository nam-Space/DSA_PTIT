#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int n, m, cnt;
bool visited[1001][1001];
int a[1001][1001];
vector<string> res;

void nhap() {
	res.clear();
	memset(visited, false, sizeof(visited));
	cnt = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
}

void Try(int i, int j) {
	if (i == n && j == m) {
		cnt++;
		return;
	}
	for (int k = 0; k < 2; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1]) {
			if (k == 0) {
				visited[i1][j1] = true;
				Try(i1, j1);
				visited[i1][j1] = false;
			}
			else {
				visited[i1][j1] = true;
				Try(i1, j1);
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
//		if (a[1][1] == 1) {
			visited[1][1] = true;
			Try(1, 1);
			visited[1][1] = false;
//		}
//		if (res.size() == 0) cout << "-1" << endl;
//		else {
//			sort(res.begin(), res.end());
//			for (string s : res) cout << s << " ";
//			cout << endl;
//		}
		cout << cnt << endl;
	}
	return 0;
}


