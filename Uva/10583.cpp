#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
#define endl "\n"

void init() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
	if (freopen("input.txt", "r", stdin));
	//if (freopen("output.txt", "w", stdout));
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


int main() {
	init();
	
	int n, m , T = 1;
	while (cin >> n >> m && n && m) {
		int a, b;
        unionFind u(n);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
            a--; b--;
            u.unionSets(a, b);
		}
        cout << "Case " << T++ << ": " << u.forests << endl;
	}

	
}
