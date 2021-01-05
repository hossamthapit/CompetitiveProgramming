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

struct edge {
    int from, to, cost;
    edge() {}
    edge(int f, int t, int cost) :from(f), to(t), cost(cost) {};
    bool operator < (const edge& ed)const {
        return cost > ed.cost;
    }
};

vector < vector < int > > curMin, curMax;
vector < int > parent, rankk, cnt;


int findSet(int a) {
    if (a == parent[a])return a;
    else return parent[a] = findSet(parent[a]);
}

int link(int a, int b) {
    if (rankk[a] > rankk[b])
        swap(a, b);
    parent[a] = b;
    cnt[b] += cnt[a];
    if (rankk[a] == rankk[b])rankk[b]++;
    return b;
}

int n;
int unionSets(int a, int b) {
    a = findSet(a), b = findSet(b);
    if (a != b) {
        int par = link(a, b);

        int inMin = INT_MAX, outMax = 0;
        for (int i = 0; i < n; i++) {
            curMax[par][i] = curMax[i][par] = max(curMax[a][i], curMax[b][i]);
            curMin[par][i] = curMin[i][par] = min(curMin[a][i], curMin[b][i]);

            if (findSet(par) == findSet(i))
                inMin = min(inMin, curMin[par][i]);
            else
                outMax = max(outMax, curMax[par][i]);
        }
        if (inMin > outMax)return  cnt[par];
    }
    return 0;
}

int main() {
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        int m; cin >> n >> m;

        parent = rankk = cnt = vector < int >(n);
        curMax = vector < vector < int > >(n , vector < int >(n , 0));
        curMin = vector < vector < int > >(n , vector < int >(n , INT_MAX));
        for (int i = 0; i < n; i++)
            cnt[i] = 1, parent[i] = i, rankk[i] = 1;

        vector < edge > edges;
        while (m--) {
            int f, t, c; cin >> f >> t >> c; f--; t--;
            curMax[f][t] = curMax[t][f] = curMin[f][t] = curMin[t][f] = c;
            edges.push_back(edge(f, t, c));
        }
        sort(all(edges));

        ll sum = 0;
        for (auto e : edges) 
            sum += unionSets(e.from, e.to);
        cout << sum << endl;

    }
}