#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 }; int dy[] = { 1,-1,0,0,1,-1,1,-1 }; typedef long long ll; using namespace std;
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin)); if (freopen("output.txt", "w", stdout));
#endif
}


vector < vector < int > > adj;
map < pair < int, int >, int > vis;
map < int, int > cnt;
vector < int > in;

void euler(int u) {

    for (auto e : adj[u]) {
        if (!vis[{max(u, e), min(e, u)}])continue;
        in[u]--; in[e]--;
        vis[{max(u, e), min(e,u)}]--;
        euler(e);
    }
    cnt[u]++;
}

int main() {
    init();

    int n, m;
    while (cin >> n >> m) {
        vis.clear();
        cnt.clear();
        in = vector < int >(n + m);
        adj = vector < vector < int > >(n+m);
        int nxt = 0;
        map < string, int > id;

        for (int i = 0; i < m; i++) {
            string a, b; cin >> a >> b;
            if (!id.count(a))id[a] = nxt++;
            if (!id.count(b))id[b] = nxt++;
            vis[{max(id[a],id[b]), min(id[b],id[a])}]++;
            adj[id[a]].push_back(id[b]);
            adj[id[b]].push_back(id[a]);
            in[id[a]]++;
            in[id[b]]++;
        }

        for (int i = 0; i < n; i++) {
            while(in[i])
                euler(i);
        }
        int ans = 1;
        for (auto e : cnt)
            ans += max(e.second - 1, 0);
        cout << ans << endl;
    }

}