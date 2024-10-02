#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ii pair<int, int>
const int N = 2e5+5, M = 6e6+5, MOD = 1e9+7, inf = 1e18;
int n, m, x, y, res, test, cnt, sum, k;
int a1[N], vis[N];
int Xmin, Xmax, Ymin, Ymax;
vector<int> ke[N];

struct node{
    int x, y;
} a[N];

void dfs(int u) {
    vis[u] = 1;
    Xmin = min(Xmin, a[u].x);
    Xmax = max(Xmax, a[u].x);
    Ymin = min(Ymin, a[u].y);
    Ymax = max(Ymax, a[u].y);
    for (auto v: ke[u]) if (!vis[v]) {
        dfs(v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    res = inf;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
        Xmin = Ymin = inf;
        Xmax = Ymax = -inf;
        dfs(i);
        res = min(res, (Xmax - Xmin + Ymax - Ymin) << 1);
    }
    cout << res;
}
