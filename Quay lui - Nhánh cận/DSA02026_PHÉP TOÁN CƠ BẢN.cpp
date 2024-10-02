#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

int ok;
string s;

void Try(int i, vector<int> v, int n){
    if (ok) return;
    for (int j = 0; j < 10; j++) {
    	v.push_back(j);
    	if (i == n) {
    		int cnt = 0;
			string tmp = s;
			for (int i = 0; i < tmp.size(); i++) {
				if (i != 3 && tmp[i] == '?') {
					tmp[i] = v[cnt++] + '0';
				}
			}
			if (tmp[0] != '0' && tmp[5] != '0' && tmp[10] != '0') {
				int a = stoi(tmp.substr(0, 2));
				int b = stoi(tmp.substr(5, 7));
				int c = stoi(tmp.substr(10, 12));
				if (tmp[3] == '+' && a + b == c) {
					ok = 1;
					cout << tmp << endl;
					return;
				}
				if (tmp[3] == '-' && a - b == c) {
					ok = 1;
					cout << tmp << endl;
					return;
				}
				if (tmp[3] == '?') {
					if (a + b == c) {
						ok = 1;
						tmp[3] = '+';
						cout << tmp << endl;
						return;
					}
					if (a - b == c) {
						ok = 1;
						tmp[3] = '-';
						cout << tmp << endl;
						return;
					}
				}
			}
		}
		else if (i < n) {
			Try(i + 1, v, n);
		}
		v.pop_back();
	}
}

int main(){
    int t; 
	cin >> t;
    cin.ignore();
    while(t--){
    	int n = 0;
    	ok = 0;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
        	if (i != 3 && s[i] == '?') n++;
		}
		vector<int> v;
		Try(1, v, n);
		if (!ok) cout << "WRONG PROBLEM!" << endl;
    }
}
