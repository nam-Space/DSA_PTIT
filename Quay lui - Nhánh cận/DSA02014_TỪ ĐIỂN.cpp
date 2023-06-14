#include <bits/stdc++.h> 
using namespace std;

int n, m, k;
string s[101];
vector<string> res;
char a[101][101];
bool ok[101][101];
int X[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int Y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void nhap() {
	cin >> k >> m >> n;
	for (int i = 1; i <= k; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	res.clear();
}

void Try(int i, int j, string tmp) {
	for (int l = 0; l < k; l++) {
		if (s[l] == tmp) {
			res.push_back(tmp);
		}
	}
	for (int l = 0; l < 8; l++) {
		int x = i + X[l];
		int y = j + Y[l];
		if (x >= 1 && x <= m && y >= 1 && y <= n && !ok[x][y]) {
			ok[x][y] = true;
			Try(x, y, tmp + a[x][y]);
			ok[x][y] = false;
		}
	}
}

int main(){ 
	int t;
	cin >> t;
	while(t--) {
		nhap();
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				memset(ok, false, sizeof(ok));
				string s = "";
				ok[i][j] = true;
				Try(i, j, s + a[i][j]);
			}
		}
		if (res.size() == 0) {
			cout << "-1" << endl;
		}
		else {
			for (string u : res) {
				cout << u << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

