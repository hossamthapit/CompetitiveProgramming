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


vector < int > parent;

int findSet(int a) {
    if (a == parent[a])return a;
    else return parent[a] = findSet(parent[a]);
}
void link(int a, int b) {
    parent[a] = b;
}
bool unionSet(int a, int b) {
    a = findSet(a), b = findSet(b);
    if (a != b)link(a, b);
    return a != b;
}

struct edge{
    int from, to, cost;
    edge(int from , int to , int cost):from(from),to(to),cost(cost){}
    bool operator < (const edge &sec)const {
        return cost < sec.cost;
    }
};

int findMST(vector < edge > edges , int mx) {

    int c = 0;
    for (auto e : edges) {      
        bool ok = unionSet(e.from, e.to);
        if (e.cost <= mx && ok) {
            c++;
        }
    }
    return c;
}

int main() {

    file();

    int n, m;
    while (cin >> n >> m && (n+m)) {
        vector < edge > edges;
        vector < int > costs;
        for (int i = 0; i < m; i++) {
            int x, y , c; cin >> x >> y >> c;
            edges.push_back(edge(x, y, c));
            costs.push_back(c);
        }

        parent = vector < int >(n);

        sort(all(edges));
        costs.erase(unique(all(costs)), costs.end());
        sort(all(costs));

        int l = 0, r = szz(costs) - 1, mid, ans = -1;

        while (l <= r) {
            mid = (l + r) / 2;

            for (int i = 0; i < n; i++)
                parent[i] = i;

            int sol = findMST(edges, costs[mid]);
            if(sol == n-1){
                ans = costs[mid];
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (ans == -1)cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

}