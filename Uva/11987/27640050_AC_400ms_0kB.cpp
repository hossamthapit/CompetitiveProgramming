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

int MAX = 900001;

vector < int > parent, rankk, cnt;
vector < ll > sum;
map < int, int > id;
int idx;

void setDsu(int n) {
    sum = vector < ll >(MAX);
    parent = rankk = cnt = vector < int >(MAX);
    for (int i = 1; i <= n; i++)
        parent[i] = i, rankk[i] = 1, sum[i] = i, cnt[i] = 1, id[i] = i;
    idx = n + 1;
}
int findSet(int a) {
    if (a == parent[a])return a;
    return parent[a] = findSet(parent[a]);
}
void link(int a, int b) {
    if (rankk[a] > rankk[b])swap(a, b);
    parent[a] = b;
    cnt[b] += cnt[a];
    sum[b] += sum[a];
    cnt[a] = 0, sum[a] = 0;
    rankk[b] += (rankk[a] == rankk[b]);
}
void unionSets(int a, int b) {
    a = findSet(a), b = findSet(b);
    if (a != b)
        link(a, b);
}
void moveSet(int a, int b) {
    int x = findSet(id[a]);
    int y = findSet(id[b]);
    if (x == y)return;
    sum[x] -= a; cnt[x]--;
    id[a] = idx++;
    sum[id[a]] = a, cnt[id[a]] = 1;
    rankk[id[a]] = 1;
    parent[id[a]] = id[a];
    unionSets(id[a], y);
}


int main() {
    init();

    int n, m;
    while (cin >> n >> m) {
        id.clear();
        setDsu(n);
        while (m--) {
            int a; cin >> a;
            if (a == 1) {
                int x, y; cin >> x >> y;
                unionSets(id[x], id[y]);
            }
            else if (a == 2) {
                int x, y; cin >> x >> y;
                moveSet(x, y);
            }
            else {
                int x; cin >> x;
                x = id[x];
                x = findSet(x);
                cout << cnt[x] << " " << sum[x] << endl;
            }
        }
    }


}