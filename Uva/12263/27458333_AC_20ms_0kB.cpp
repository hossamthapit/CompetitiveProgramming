#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;

void file() {
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}


int n;
vector < int > v;
vector < bool > vis;
vector < int > topSort , indeg;
bool adjMat[501][501];

void bfs() {

    queue < int > q;
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);

    while (szz(q)) {
        int u = q.front(); q.pop();

        topSort.push_back(u);
        vis[u] = 1;

        for (int i = 1; i <= n; i++)
            if (adjMat[u][i])
                if (--indeg[i] == 0)
                    q.push(i);
    }

    if (szz(topSort) != n)cout << "IMPOSSIBLE";
    else for (int i = 0; i < n; i++)!i ? cout << topSort[i] : cout << " " << topSort[i];
    cout << endl;
}

int main() {
    file();
    fast();

    int t;
    cin >> t;
    while (t--) {

        cin >> n;
        v.resize(n);
        vis = vector < bool >(n + 1);
        indeg.resize(n + 1);
        topSort.clear();
        memset(adjMat, 0, sizeof adjMat);

        for (auto& e : v)cin >> e;

        for (int i = 0; i < n;i++)
            for (int k = i + 1; k < n; k++)
                adjMat[v[i]][v[k]] = 1;

        int m; cin >> m;

        while (m--) {
            int a, b; cin >> a >> b;
            swap(adjMat[a][b], adjMat[b][a]);
        }

        for (int i = 0; i <= n; i++) {
            indeg[i] = 0;
            for (int j = 0; j <= n; j++)
                indeg[i] += adjMat[j][i];
        }
        bfs();
    }
}