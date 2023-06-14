#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[101][101];
int n, k, used[10001];
string s;
vector<string> res;

void nhap() {
	cin >> s;
}

int main(){
	int t;
	cin >> t;
	while(t--) {
		nhap();
		do {
			cout << s << " ";
		} while(next_permutation(s.begin(), s.end()));
		cout << endl;
	}
}
