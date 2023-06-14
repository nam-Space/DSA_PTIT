#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int n = 8, ans;
bool visited[101][101];
vector<string> res;
int a[101][101], x[101];
int d1[101], d2[101], cot[101];

void nhap() {
	ans = 0;
	memset(d1, 0, sizeof(d1));
	memset(d2, 0, sizeof(d2));
	memset(cot, 0, sizeof(cot));
	memset(x, 0, sizeof(x));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
}

void ghiNhan() {
	int sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i][x[i]];
	ans = max(ans, sum);
}

void Try(int i) {
	for (int j = 1; j <= n; j++) {
		if (!d1[i - j + n] && !d2[i + j - 1] && !cot[j]) {
			x[i] = j;
			d1[i - j + n] = d2[i + j - 1] = cot[j] = 1;
			if (i == n) ghiNhan();
			else Try(i + 1);
			d1[i - j + n] = d2[i + j - 1] = cot[j] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		Try(1);
		cout << ans << endl;
	}
	return 0;
}



