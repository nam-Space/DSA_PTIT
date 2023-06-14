#include <bits/stdc++.h> 
using namespace std;

string a[105];

string add(string a, string b) {
	string res = "";
	while(a.length() < b.length()) a = "0" + a;
	while(b.length() < a.length()) b = "0" + b;
	int nho = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		int tmp = (a[i] - '0') + (b[i] - '0') + nho;
		nho = tmp / 10;
		tmp = tmp % 10;
		res = to_string(tmp) + res;
	}
	if (nho) {
		res = to_string(nho) + res;
	}
	return res;
}

string mul(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	int len = len1 + len2;
	vector<int> a, b;
	for (int i = 0; i < len1; i++) {
		a.push_back(s1[i] - '0');
	}
	for (int i = 0; i < len2; i++) {
		b.push_back(s2[i] - '0');
	}
	
	vector<vector<int>>res(len2);
	
	int index = 0;
	for (int i = len2 - 1; i >= 0; i--) {
		int nho = 0, so = 0;
		int t = 0;
		while(t < index){
			res[index].push_back(0);
			t++;
		}
		for (int j = len1 - 1; j >= 0; j--) {
			so = a[j] * b[i] + nho;
			res[index].push_back(so % 10);
			nho = so / 10;
		}
		if (nho) {
			res[index].push_back(nho);
		}
		while(res[index].size() < len) {
			res[index].push_back(0);
		}
		reverse(res[index].begin(), res[index].end());
		index++;
	}
	
	int nho = 0;
	string ans = "";
	for (int j = res[0].size() - 1; j >= 0; j--) {
		int so = 0;
		for (int i = 0; i < res.size(); i++) {
			so += res[i][j];
		}
		so += nho;
		nho = so / 10;
		so %= 10;
		ans = to_string(so) + ans;
	}
	if (nho) {
		ans = to_string(nho) + ans;
	}
	while(ans[0] == '0') ans.erase(ans.begin());
	return ans;
}

void init() {
	a[0] = "1";
	a[1] = "1";
	for (int i = 2; i <= 100; i++) {
		string tmp = "";
		for (int j = 0; j < i; j++) {
			string tmp1 = "0";
			tmp = add(tmp, mul(a[j], a[i - j - 1]));
		}
		a[i] = tmp;
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}



