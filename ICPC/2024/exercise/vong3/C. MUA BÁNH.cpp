#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool check = false;
	// 4a + 7b = N
    // b = (N - 4a) / 7
    // loop i = 0 to (n / 4)
    for (int i = 0; i <= n / 4; i++) {
    	if ((n - 4 * i) % 7 == 0) {
    		check = true;
    		break;
		}
	}
	if (check) cout << "Yes" << endl;
	else cout << "No" << endl;
}