#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

vector<string> v;
vector<string> ans;

int mu(string s) {
	int sum = 0;
	int index = s.find("^") + 1;
	for (int i = index; i < s.size(); i++) {
		sum = sum * 10 + s[i] - '0';
	}
	return sum;
}

bool cmp(string s1, string s2) {
	int mu1 = mu(s1);
	int mu2 = mu(s2);
	return mu1 > mu2;
} 

void nhap() {
	v.clear();
	ans.clear();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	stringstream ss1(s1);
	stringstream ss2(s2);
	string tmp;
	while(ss1 >> tmp) {
		if (tmp != "+") v.push_back(tmp);
	}
	while(ss2 >> tmp) {
		if (tmp != "+") v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
}

int soHang(string s) {
	int sum = 0;
	int index = s.find("*");
	for (int i = 0; i < index; i++) {
		sum = sum * 10 + s[i] - '0';
	}
	return sum;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--) {
		nhap();
		stack<string> st;
		reverse(v.begin(), v.end());
		for (string s : v) st.push(s);
		while(!st.empty()) {
			string s1 = st.top(); st.pop();
			string res = s1;
			int soMu1 = mu(s1);
			int soHang1 = soHang(s1);
			int tongHang = soHang1;
			if (!st.empty()) {
				string s2 = st.top();
				int soMu2 = mu(s2);
				int soHang2 = soHang(s2);
				if (soMu1 == soMu2) {
					tongHang += soHang2;
					res = "";
					res = to_string(tongHang) + "*x^" + to_string(soMu1);
					st.pop();
				}
			}
			ans.push_back(res);
		}
		for (int i = 0; i < ans.size() - 1; i++) {
			cout << ans[i] << " + ";
		} 
		cout << ans[ans.size() - 1] << endl;
	} 
}

