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

/// MST_Kruskal

struct unionFind {
    vector < int > rankk, parent;
    int forests;
    unionFind(int n) {
        rankk = vector < int >(n), parent = vector < int >(n);
        forests = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rankk[i] = 1;
        }
    }
    int findSet(int x) {
        if (x == parent[x])return x;
        return parent[x] = findSet(parent[x]);
    }
    void link(int x, int y) {
        if (rankk[x] > rankk[y])swap(x, y);
        parent[x] = y;
        if (rankk[x] == rankk[y])rankk[y]++;
    }
    bool unionSets(int x, int y) {
        x = findSet(x), y = findSet(y);
        if (x != y) {
            link(x, y);
            forests--;
        }
        return x != y;
    }
    bool sameSet(int x, int y) {
        return findSet(x) == findSet(y);
    }
    vector < vector < int > > connectedComponent() {
        vector < vector < int > > comps(szz(parent));
        for (int i = 0; i < szz(parent); i++) {
            comps[findSet(i)].push_back(i);
        }
    }
};

struct edge {
    int from, to , idx;
    ll w;
    edge(){}
    edge(int from, int to, ll w) :from(from), to(to), w(w) {}
    bool operator < (const edge& e)const {
        return w > e.w;
    }
};

pair < int , vector < edge > >  MST_kruskal(vector < edge > edgeList, int n) {
    unionFind uf(n);
    vector < edge > edges;
    double mstCost = 0;
    priority_queue < edge > q;
    for (auto p : edgeList)q.push(p);

    while (!q.empty()) {
        edge p = q.top(); q.pop();
        if(p.w == -1)continue;
        if (uf.unionSets(p.from, p.to)) {
            mstCost += p.w;
            edges.push_back(p);
        }
    }
    if (szz(edges) != n - 1)return {-1,edges};
    else return {mstCost,edges};
}


int main() {
    file();

    int t , T = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector < edge > v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i].from >> v[i].to >> v[i].w;
            v[i].idx = i;
            v[i].from--; v[i].to--;
        }

        pair < int , vector < edge > > mst = MST_kruskal(v, n);


        cout << "Case #" << T++ << " : ";
        if (mst.first == -1)cout << "No way" << endl;
        else {
            int cost = INT_MAX;
            for (auto e : mst.second) {
                int temp = v[e.idx].w;
                v[e.idx].w = -1;
                int sol = MST_kruskal(v, n).first;
                if (sol != -1) {
                    cost = min(cost, sol);
                }
                v[e.idx].w = temp;
            }
            if (cost != INT_MAX)
                cout << cost << endl;
            else
                cout << "No second way" << endl;
        }
    }
}