#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int n, k, a[101];
string s;

void selection_sort() {
	for (int i = 1; i <= n - 1; i++) {
		int min_pos = i;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] >= a[min_pos]) {
				min_pos = j;
			}
		}
		if(a[min_pos] > a[i] && k > 0) {
			swap(a[i], a[min_pos]);
			k--;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> k >> s;
		n = s.size();
		for (int i = 1; i <= n; i++) {
			a[i] = s[i - 1] - '0';
		}
		selection_sort();
		for (int i = 1; i <= n; i++) cout << a[i];
		cout << endl;
	}
	return 0;
}



