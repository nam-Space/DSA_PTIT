#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
vector<pair<int, int>> edge;

int main(){
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp) {
			if (stoi(tmp) > i) {
				edge.push_back({i, stoi(tmp)});
			}
		}
	}
	for (auto it : edge) {
		cout << it.first << " " << it.second << endl;
	}
	
	return 0;
}



