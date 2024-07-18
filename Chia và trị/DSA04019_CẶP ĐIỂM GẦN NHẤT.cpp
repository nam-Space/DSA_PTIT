#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

double Distance(pair<double, double> A, pair<double, double> B) {
	return double(sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second)));
}

bool cmp(pair<double, double> A, pair<double, double> B) {
	return A.second > B.second;
}

double _Min1(pair<double, double> *M, int n) {
	double a = FLT_MAX;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			a = min(a, Distance(M[i], M[j]));
	return a;
}

double _Min2(vector<pair<double, double>> X, double minx) {
	double a = minx;
	sort(X.begin(), X.end());
	for (int i = 0; i < X.size(); i++)
		for (int j = i + 1; j < X.size() && (X[j].second - X[i].second) < a; j++)
			a = min(a, Distance(X[i], X[j]));
	return a;
}

double Load(pair<double, double> *M, int n) {
	if (n <= 3) return  _Min1(M,n);
	int mid = n / 2;
	double minx = min(Load(M, mid), Load(M + mid, n - mid));
	vector<pair<double, double>> X;
	for (int i = 0; i < n; i++)
		if (abs(M[i].first - M[mid].first) < minx)
			X.push_back(M[i]);
	return min(minx, _Min2(X,minx));
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		pair<double, double> M[100000];
		for (int i = 0; i < n; i++)cin >> M[i].first >> M[i].second;
		sort(M, M + n);
		if(n > 1) {
			cout << setprecision(6) << fixed << Load(M, n) << endl;
		}
		else cout<<endl;
	}
}