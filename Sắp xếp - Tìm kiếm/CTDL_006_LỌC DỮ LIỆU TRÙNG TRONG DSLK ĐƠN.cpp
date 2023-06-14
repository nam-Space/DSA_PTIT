#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main(){
	int n;
	cin >> n;
	int a[n];
	set<int> se;
	for (int &x : a) {
		cin >> x;
		se.insert(x);
	}
	for (int x : a) {
		if (se.find(x) != se.end()) {
			cout << x << " ";
			se.erase(x);
		}
	}
}
