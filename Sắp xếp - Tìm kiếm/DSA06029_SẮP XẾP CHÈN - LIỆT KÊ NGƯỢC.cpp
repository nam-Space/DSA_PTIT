#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void insertion_sort(int a[], int n) {
	int cnt = 0;
	vector<string> res;
	for (int i = 1; i < n; i++) {
		string s = "Buoc " + to_string(cnt) + ": ";
		for (int j = 0; j < i; j++) {
			s += to_string(a[j]) + " ";
		}
		s = s.substr(0, s.size() - 1);
		res.push_back(s);
		cnt++;
		int pos = i - 1; 
		int x = a[i];
		while(pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
	string s = "Buoc " + to_string(cnt) + ": ";
	for (int i = 0; i < n; i++) {
		s += to_string(a[i]) + " ";
	}  
	s = s.substr(0, s.size() - 1);
	res.push_back(s);
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
		insertion_sort(a, n);
	}
	return 0;
}

