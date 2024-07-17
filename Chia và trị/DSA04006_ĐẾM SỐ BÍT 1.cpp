#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int mod = 1e9 + 7;

vector<ll> a;

void layTrungTam(ll n) {
	ll soLuongTrungTam = 1ll * log2(n);
	for (ll i = 1; i <= soLuongTrungTam; i++) {
		a.push_back(1ll * pow(2, i));
	}
}

ll val(ll k, ll n, ll pos) {
	if (k % 2 == 1) return 1;
	if (k < a[pos]) return val(k, n / 2, pos - 1);
	if (k == a[pos]) return n % 2;
	return val(a[pos] - (k - a[pos]), n / 2, pos - 1);
}

int main(){
	int t;
    cin >> t;
    while(t--){
    	a.clear();
    	ll n, l, r;
    	cin >> n >> l >> r;
    	ll res = 0;
    	layTrungTam(n);
    	for (ll i = l; i <= r; i++) {
    		res += val(i, n, a.size() - 1);
		}
		cout << res << endl;
    }
    return 0;
}
