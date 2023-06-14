#include<bits/stdc++.h>
using namespace std;

using ll = long long;

struct Data {
	int first, second, third;
};

int res;
bool visited[101][101];

string bienDoi(string s) {
	if (s[0] == 'a') s[0] = '1';
	else if (s[0] == 'b') s[0] = '2';
	else if (s[0] == 'c') s[0] = '3';
	else if (s[0] == 'd') s[0] = '4';
	else if (s[0] == 'e') s[0] = '5';
	else if (s[0] == 'f') s[0] = '6';
	else if (s[0] == 'g') s[0] = '7';
	else s[0] = '8';
	return s;
}

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(string s1, string s2) {
	queue<Data> q;
	q.push({s1[0] - '0', s1[1] - '0', 0});
	visited[s1[1] - '0'][s1[0] - '0'] = true;
	while(!q.empty()) {
		Data v = q.front(); q.pop();
		if (v.first == s2[0] - '0' && v.second == s2[1] - '0') res = min(res, v.third);
		for (int i = 0; i < 8; i++) {
			int i1 = v.second + dx[i];
			int j1 = v.first + dy[i];
			if (i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && !visited[i1][j1]) {
				q.push({j1, i1, v.third + 1});
				visited[i1][j1] = true;
			} 
		}
	}
} 

int main(){
	int t;
	cin >> t;
	while(t--) {
		res = 1e9;
		memset(visited, false, sizeof(visited));
		string s1, s2;
		cin >> s1 >> s2;
		s1 = bienDoi(s1);
		s2 = bienDoi(s2);
		bfs(s1, s2);
		cout << res << endl;
	}
}
