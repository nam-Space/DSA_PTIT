#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

int f[100001];

int main(){
	int t;
    t = 1;
    while(t--){
    	memset(f, 0, sizeof(f));
    	int n;
    	cin >> n;
    	int a[n];
    	int max_cnt = INT_MIN;
    	for (int &x : a) cin >> x;
    	for (int x : a) {
    		f[x] = f[x - 1] + 1;
    		max_cnt = max(max_cnt, f[x]);
		}
		cout << n - max_cnt << endl;
		
    }
}
