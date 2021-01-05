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

vector < set < int > > adj;
vector < vector < int > > parent;

void bfs(int source) {
    parent[source] = vector < int >(szz(adj),-1);
    vector < int > dist(szz(parent),-1);
    parent[source][source] = source;
    queue < pair < int, int > > q;
    q.push({ source,0 });
    while (szz(q)) {
        int u = q.front().first, dis = q.front().second; q.pop();
        if (dist[u] != -1)continue;
        dist[u] = dis;
        for (auto e : adj[u])
            if (dist[e] == -1) {
                q.push({ e,dis + 1 });
                if(parent[source][e]==-1)
                    parent[source][e] = u;
            }
    }
}

int main() {
    init();

    int n;
    char temp ;
    string s;

    while (cin >> n && n) {
        cin.ignore();
        adj = vector < set < int > > (n);
        parent = vector < vector < int > >(n);
        
        for (int i = 0; i < n; i++) {
            int u , v; cin >> u;
            getline(cin, s);
            stringstream str(s);
            while (str >> temp >> v) {
                adj[u - 1].insert(v - 1);
            }
        }

        for (int i = 0; i < n; i++)
            bfs(i);

        cout << "-----" << endl;
        int m; cin >> m;
        while (m--) {
            int a, b; cin >> a >> b; a--, b--;
            vector < int > path;

            while (parent[a][b] != -1) {
                path.push_back(b+1);
                if (b == a)break;
                b = parent[a][b];
            }
            reverse(all(path));

            if (b == a)for (int i = 0; i < szz(path); i++)if (!i)cout << path[i]; else cout <<" " << path[i];
            else cout << "connection impossible";
            cout << endl;
        }
    }




}