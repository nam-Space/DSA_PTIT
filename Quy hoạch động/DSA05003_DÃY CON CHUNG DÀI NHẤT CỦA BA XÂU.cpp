#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int dp[101][101][101];

int main(){
	int t;
	cin >> t;
	while(t--) {
		int x, y, z;
		cin >> x >> y >> z;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				for (int k = 1; k <= z; k++) {
					if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) {
						dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					}
					else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
		cout << dp[x][y][z] << endl;
	} 
	return 0;
}

