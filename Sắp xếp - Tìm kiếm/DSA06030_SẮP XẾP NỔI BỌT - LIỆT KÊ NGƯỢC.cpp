#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void buble_sort(int a[], int n) {
	int cnt = 0;
	vector<string> res;
	for (int i = 0; i < n - 1; i++) {
		bool check = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				check = true;
				swap(a[j], a[j + 1]);
			}  
		}
		if (check) {
			cnt++;
			string s = "Buoc " + to_string(cnt) + ": ";
			for (int j = 0; j < n; j++) {
				s += to_string(a[j]) + " ";
			} 
			s = s.substr(0, s.size() - 1);
			res.push_back(s);
		}
	}
	reverse(res.begin(), res.end());
	for (string s : res) cout << s << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int *a = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		buble_sort(a, n);
	}
	return 0;
}

