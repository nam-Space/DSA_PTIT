#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int parent[1001];
vector<pair<double, double>> v;

struct Edge {
	int i1, j1;
	double len;
};

int find(int i) {
	if (parent[i] == -1) return i;
	int x = find(parent[i]);
	parent[i] = x;
	return x;
}

double calc_len(int i, int j) {
	pair<double, double> a  = v[i];
	pair<double, double> b  = v[j];
	double len = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	return len;
}

bool cmp(Edge a, Edge b) {
	return a.len < b.len;
}

int main(){
	int t; 
	cin >> t;
	while(t--){
		v.clear();
		memset(parent, -1, sizeof(parent));
		vector<Edge> canh;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			v.push_back({x, y});
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				double len = calc_len(i, j);
				canh.push_back({i, j, len});
			}
		}
		sort(canh.begin(), canh.end(), cmp);
		double sum = 0;
		for (int i = 0; i < canh.size(); i++) {
			Edge e = canh[i];
			int a = find(e.i1);
			int b = find(e.j1);
			if (a != b) {
				sum += e.len;
				parent[b] = a;
			}
		}
		cout << fixed << setprecision(6) << sum << endl;
	}
	return 0;
}



