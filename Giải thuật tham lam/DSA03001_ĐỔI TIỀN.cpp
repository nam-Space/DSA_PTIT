#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--) {
    	int money[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    	int n;
    	cin >> n;
    	int cnt = 0;
    	for (int i = 9; i >= 0; i--) {
    		cnt += n / money[i];
    		n = n % money[i];
		}
		cout << cnt << endl;
	}
}


