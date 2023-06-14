#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int a[101];
int x[101];
int n, m, k, used[101];
vector<string> res;

void nhap() {
	cin >> n;
}

void Try(int n, char goc, char trungGian, char dich) {
	if (n == 0) return;
	if (n == 1) cout << goc << " -> " << dich << endl;
	else {
		Try(n - 1, goc, dich, trungGian);
		Try(1, goc, trungGian, dich);
		Try(n - 1, trungGian, goc, dich);
	}
}


int main(){
	int t;
	t = 1;
	while(t--) {
		nhap();
		Try(n, 'A', 'B', 'C');
	}
}

