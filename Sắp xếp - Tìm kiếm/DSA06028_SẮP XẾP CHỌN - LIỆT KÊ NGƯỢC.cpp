#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void selection_sort(int a[], int n) {
	int cnt = 0;
	vector<string> res;
	for (int i = 0; i < n - 1; i++) {
		int min_pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_pos]) {
				min_pos = j;
			}
		}
		swap(a[i], a[min_pos]);
		cnt++;
		string s = "Buoc " + to_string(cnt) + ": ";
		for (int j = 0; j < n; j++) {
			s += to_string(a[j]) + " ";
		}
		s = s.substr(0, s.size() - 1);
		res.push_back(s);
	}
	reverse(res.begin(), res.end());
	for (string s : res) cout << s << endl;
}

int main(){
	int t;
	t = 1;
	while(t--) {
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		selection_sort(a, n);
	}
	return 0;
}

