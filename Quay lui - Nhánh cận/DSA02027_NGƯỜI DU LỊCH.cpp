#include <bits/stdc++.h> 
using namespace std;

int n, cmin, res; 
int a[101][101], x[101];
int visited[101];

void Try(int i, int sum) {
	if (sum + cmin * (n - i - 1) > res) return;
	for (int j = 1; j <= n; j++) {
		if (!visited[j]) {
			x[i] = j;
			visited[j] = true;
			if (i == n) res = min(res, sum + a[x[i - 1]][x[i]] + a[x[i]][1]);
			else Try(i + 1, sum + a[x[i - 1]][x[i]]);
			visited[j] = false;
		}
	}
}

int main(){ 
	int t;
	t = 1;
	while(t--) {
		res = cmin = INT_MAX;
		memset(visited, false, sizeof(visited));
		memset(x, 0, sizeof(x));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] != 0) cmin = min(cmin, a[i][j]);
			}
		}
		x[1] = 1;
		visited[1] = true;
		Try(2, 0);
		cout << res << endl;
	}
	return 0;
}
