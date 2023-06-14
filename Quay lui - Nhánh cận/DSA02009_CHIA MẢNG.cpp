#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k, sum;
int a[101], used[101];
bool check;

void Try(int s, int cnt) {
	if (cnt == k) {
		check = true;
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (!used[j] && !check) {
			used[j] = 1;
			if (s + a[j] < sum) Try(s + a[j], cnt);
			else if (s + a[j] == sum) Try(0, cnt + 1);
			used[j] = 0;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		check = false;
		sum = 0;
		memset(used, 0, sizeof(used));
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		if (sum % k != 0) {
			cout << "0" << endl;
			continue;
		}
		sum /= k;
		Try(0, 0);
		cout << check << endl;
	}
	return 0;
}



