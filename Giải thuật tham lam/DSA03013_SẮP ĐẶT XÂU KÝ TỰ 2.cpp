#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int d;
    	cin >> d;
    	string s;
    	cin >> s;
    	int cnt[301] = {0};
    	for (char x : s) cnt[x]++;
    	int max_ele = *max_element(cnt, cnt + 301);
    	if (s.size() - max_ele >= (d - 1) * (max_ele - 1)) cout << "1" << endl;
    	else cout << "-1" << endl;
	}
}


