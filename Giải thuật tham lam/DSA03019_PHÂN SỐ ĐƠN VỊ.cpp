#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

void phan_tach(ll tu, ll mau) {
	if (mau % tu == 0) {
		cout << "1/" << mau / tu;
		return;
	}
	ll mauNew = mau / tu + 1;
	cout << "1/" << mauNew << " + ";
	phan_tach(tu * mauNew - mau, mau * mauNew);
}

int main(){
    int t;
    cin >> t;
    while(t--) {
    	ll tu, mau;
    	cin >> tu >> mau;
    	phan_tach(tu, mau);
    	cout << endl;
	}
}


