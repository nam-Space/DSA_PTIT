#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<string> v;

int mu(string s) {
	string sum = "";
	int index = s.find("^") + 1;
	for (int i = index; i < s.size(); i++) {
		sum += s[i];
	}
	return stoi(sum);
}

bool cmp(string s1, string s2) {
	int mu1 = mu(s1);
	int mu2 = mu(s2);
	return mu1 > mu2;
}

void nhap() {
	v.clear();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	stringstream ss1(s1);
	stringstream ss2(s2);
	string token;
	while(ss1 >> token) {
		if (token != "+") v.push_back(token);
	}
	while(ss2 >> token) {
		if (token != "+") v.push_back(token);
	}
	sort(v.begin(), v.end(), cmp);
}

int hang(string s) {
	string sum = "";
	int index = s.find("*");
	for (int i = 0; i < index; i++) {
		sum += s[i];
	}
	return stoi(sum);
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		nhap();
		stack<string> st;
		int mu_max = mu(v[0]);
		int res[mu_max + 1];
		int a[mu_max + 1];
		memset(res, 0, sizeof(res));
		memset(a, 0, sizeof(a));
		for (int i = 0; i < v.size(); i++) {
			int soMu = mu(v[i]);
			int soHang = hang(v[i]);
			res[soMu] += soHang;
			a[soMu] = 1;
		}
		string ans = "";
		for (int i = mu_max; i >= 0; i--) {
			if (a[i]) {
				ans += " + " + to_string(res[i]) + "*x^" + to_string(i);
			}
		}
		cout << ans.substr(3) << endl;
	} 
}
