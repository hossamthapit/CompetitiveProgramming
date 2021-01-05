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

vector < bool > vis;
vector < set < int > > adj;

void dfs(int u) {
    if (vis[u])return;
    vis[u] = 1;
    for(auto &e : adj[u]) {
        if (!vis[e])
            dfs(e);
    }
}

int main() {
    file();

    
    int t;
    cin >> t;

    string largest ,  oldL;
    cin >> largest;
    oldL = largest;

    vector < int > ret;

    while (t--) {
        map < int, int > id; int idx = 1;
        adj = vector < set < int > >(28);
        vis = vector < bool >(28, 0);
        
        string s;
        largest = oldL;
        while (cin >> s) {
            if (szz(s) == 1)break;
            if (!id[s[0]])id[s[0]] = idx++;
            if (!id[s[1]])id[s[1]] = idx++;
            adj[id[s[0]]].insert(id[s[1]]);
            adj[id[s[1]]].insert(id[s[0]]);
        }
        oldL = s;

        int ans = 0;
        for (int i = 1; i <= largest[0] - 'A'+ 1; i++) {
            if (!vis[i]) {
                dfs(i);
                ans++;
            }
        }
        ret.push_back(ans);
    }
    for (int i = 0; i < szz(ret); i++) {
        if (!i)cout << ret[i] << endl;
        else cout << endl << ret[i] << endl;
    }
}