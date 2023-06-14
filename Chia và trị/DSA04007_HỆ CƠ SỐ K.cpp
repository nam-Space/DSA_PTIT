#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int t;
	cin >> t;
	while(t--) {
		int k;
		cin >> k;
		string s1, s2;
		cin >> s1 >> s2;
		while(s1.size() < s2.size()) s1 = "0" + s1;
		while(s2.size() < s1.size()) s2 = "0" + s2;
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		int nho = 0;
		string s3 = "";
		for (int i = 0; i < s1.size(); i++) {
			int tong = (s1[i] - '0') + (s2[i] - '0') + nho;
			nho = tong / k;
			tong = tong % k;
			s3 += to_string(tong);
		}
		if (nho) s3 += to_string(nho);
		reverse(s3.begin(), s3.end());
		cout << s3 << endl;
	}
	return 0;
}

