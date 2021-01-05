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

vector < int > topSort;
vector < bool > vis;
vector < vector < int > > adj;

void dfs(int u , bool on = 0) {
    vis[u] = 1;
    for (auto e : adj[u])
        if (!vis[e])
            dfs(e,on);
    if(on)topSort.push_back(u);
}


void start() {
    int n, m;
    cin >> n >> m;
    adj = vector < vector < int > >(n + 1);
    vis = vector < bool >(n + 1, 0);
    topSort.clear();
    
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++)
        if(!vis[i])
            dfs(i,1);

    reverse(all(topSort));
    int cnt = 0 ;
    vis = vector < bool >(n + 1, 0);
    for (auto e : topSort)
        if (!vis[e])
            dfs(e), cnt++;

    cout << cnt << endl;
}

int main() {
    init();
    int t = 1 , T = 1;
    cin >> t;
    while (t--) {
        cout << "Case " << T++ << ": ";
        start();
    }
}