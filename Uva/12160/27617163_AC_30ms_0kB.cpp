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


int MAX = 10000;

vector < int > v;

int bfs(int start, int reach) {
    vector < int > vis(MAX);
    queue < pair < int, int > > q;
    q.push({ start,0 });
    while (szz(q)) {
        int u = q.front().first, dist = q.front().second; q.pop();
        if (vis[u])continue;
        if (u == reach)return dist;
        vis[u] = 1;
        for (auto e : v)
            if (!vis[(u + e)% MAX])
                q.push({ (u + e) % MAX,dist + 1 });
    }
    return -1;
}

int main() { 
    init();
    
    int a, b, k , T = 1;
    while (cin >> a >> b >> k && (a + b + k)) {
        v.resize(k);
        for (auto& e : v)cin >> e;
        int sol = bfs(a, b);
        cout << "Case " << T++ << ": ";
        if (sol == -1)cout << "Permanently Locked" << endl;
        else cout << sol << endl;
    }

    
}