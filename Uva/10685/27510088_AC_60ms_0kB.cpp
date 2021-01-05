#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

vector < vector < int > > adj;
vector < bool > vis;

int dfs(int u) {
    if (vis[u])return 0;
    vis[u] = 1;
    int ret = 1;
    for (auto e : adj[u]) 
        if (!vis[e])
            ret += dfs(e);
    return ret;
}

int main() {
    file();

    int n, m;
    while (cin >> n >> m && (n + m)) {

        adj = vector < vector < int > >(n);
        vis = vector < bool >(n, 0);
        vector < int > eat(n), eaten(n);
        

        map < string, int > value;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            value[s] = i;
        }

        for (int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            adj[value[b]].push_back(value[a]);
            adj[value[a]].push_back(value[b]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) 
            ans = max(ans, dfs(i));

        cout << ans << endl;


    }

}