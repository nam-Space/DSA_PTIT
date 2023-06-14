#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

ll ugly[10001];

void init() {
	ugly[1] = 1;
	int i2 = 1, i3 = 1, i5 = 1;
	for (int i = 2; i <= 10000; i++) {
		ugly[i] = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));
		if (ugly[i] % 2 == 0) i2++;
		if (ugly[i] % 3 == 0) i3++;
		if (ugly[i] % 5 == 0) i5++;
	}
}

int main(){
	init();
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	cout << ugly[n] << endl;
	}
}


