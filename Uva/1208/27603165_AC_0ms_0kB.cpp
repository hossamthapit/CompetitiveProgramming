#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;

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
    vector < vector < int > > connectedComponent() {
        vector < vector < int > > comps(szz(parent));
        for (int i = 0; i < szz(parent); i++) {
            comps[findSet(i)].push_back(i);
        }
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

bool comp(edge p1, edge p2) {
    pair < pair < int, int >, ll > pp = { {p1.w,p1.from},p1.to };
    pair < pair < int, int >, ll > pp2 = { {p2.w,p2.from},p2.to };
    return pp < pp2;
}

vector < edge >  MST_kruskal(vector < edge > edgeList, int n) {
    unionFind uf(n);
    ll mstCost = 0;
    vector < edge > mst;

    sort(all(edgeList),comp);
    int idx = 0;

    while (idx < szz(edgeList)) {
        edge p = edgeList[idx++];
        if (uf.unionSets(p.from, p.to)) {
            mstCost += p.w;
            mst.push_back(p);
        }
    }
    return mst;

}

int main() {

    file();

    int n, t , T = 1;
    cin >> t;
    while (t--) {
        cin >> n;

        vector < edge > v;
        char a;
        int x;
        for (int i = 0; i < n; i++) {
            for(int k = 0; k < n; k++) {
                cin >> x;
                if (k != n - 1)cin >> a;
                if(x)v.push_back({ min(i,k),max(i,k),x });
            }
        }


        cout << "Case " << T++ << ":" << endl;
        v = MST_kruskal(v, n);

        sort(all(v),comp);

        for (auto e : v)
            cout << min(char(e.from + 'A'), char(e.to + 'A')) << "-" << max(char(e.from + 'A'), char(e.to + 'A')) << " " << e.w << endl;

    }


}