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
};

struct edge {
    int from, to;
    ll w;
    edge(int from, int to, ll w) :from(from), to(to), w(w) {}
    bool operator < (const edge& e)const {
        return w > e.w;
    }
};

ll  MST_kruskal(vector < edge > edgeList, int n) {
    unionFind uf(n);
    vector < edge > edges;
    ll mstCost = 0;
    priority_queue < edge > q;
    for (auto p : edgeList)q.push(p);

    while (!q.empty()) {
        edge p = q.top(); q.pop();
        if (uf.unionSets(p.from, p.to)) {
            mstCost += p.w;
            edges.push_back(p);
        }
    }
    return mstCost;

}


int main() {
    file();
    
    int n, m;
    while (cin >> n >> m&& n && m) {
        vector < edge > edges;

        ll total = 0;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back(edge(a, b, c));
            total += c;
        }

        cout << total - MST_kruskal(edges, n) << endl;
    }
}