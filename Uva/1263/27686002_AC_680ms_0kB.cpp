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

void dfs(int u, bool on = 0) {
    vis[u] = 1;
    for (auto e : adj[u])
        if (!vis[e])
            dfs(e, on);
    if (on)topSort.push_back(u);
}


int solve(int n) {
    vis = vector < bool >(n , 0);

    topSort.clear();

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i, 1);

    reverse(all(topSort));
    int cnt = 0;
    vis = vector < bool >(n, 0);
    for (auto e : topSort)
        if (!vis[e])
            dfs(e), cnt++;

    return cnt;
}


int n, m;

struct point {
    int x, y, d;
    double x1, x2, y1, y2;
    void set() {
        x1 = x - d / 2;
        x2 = x + d / 2;
        y1 = y - d / 2;
        y2 = y + d / 2;
    }
};


bool intersect(point a, point b) {
    if (b.x >= a.x1 && b.x <= a.x2 && b.y >= a.y1 && b.y <= a.y2)return 1;
    return 0;
}

int main() {
   init();
    
   int n, t;
   cin >> t;
   while (t--) {
       cin >> n;
       vector < point > v(n);
       adj = vector < vector < int > >(n);
       for (auto& e : v)cin >> e.x >> e.y >> e.d;
       for (auto& e : v)e.set();

       for (int i = 0; i < n; i++) 
           for (int k = 0; k < n; k++) 
               if (i != k && intersect(v[i], v[k]))
                   adj[i].push_back(k);

       cout << solve(n) << endl;

   }
  

}