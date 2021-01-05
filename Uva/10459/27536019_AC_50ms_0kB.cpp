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

int n;
vector < int > mxDist;
vector < int > indeg;
vector < vector < int > > adj;

vector<int> findBestRoot(){

    // create indeg for each node before use it :)

    queue<int> q;

    int vertices = n;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 1)
            q.push(i), vertices--;

    while (szz(q) + vertices > 2) {

        int sz = q.size();

        while(sz--) {

            int t = q.front();
            q.pop();

            for (auto j : adj[t])
                if (--indeg[j] == 1)
                    q.push(j), vertices--;
        }
    }

    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    sort(all(res));
    return res;
}

vector < int > findWorstRoot(vector < int > bestRoot) {

    vector < int > dist(n) , vis(n);
    queue < pair < int, int > > q;
    for (auto e : bestRoot)
        q.push({ e,0 });

    while (szz(q)) {
        pair < int, int >p = q.front(); q.pop();

        if (vis[p.first])continue;
        vis[p.first] = 1;
        dist[p.first] = p.second;

        for (auto e : adj[p.first])
            if (!vis[e])
                q.push({ e,p.second + 1 });
    }

    int mx = *max_element(all(dist));

    vector < int > worst;

    for (int i = 0; i < n; i++)
        if (dist[i] == mx)
            worst.push_back(i);
    sort(all(worst));
    return worst;
}





int main() {
    file();

    while (cin >> n) {
        adj = vector < vector < int > >(n);
        mxDist.resize(n);
        indeg = vector < int >(n);


        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            while (m--) {
                indeg[i]++;
                int a;
                cin >> a;
                adj[i].push_back(a - 1);
            }
        }

        vector < int > best = findBestRoot();

        cout << "Best Roots  : ";
        for (int i = 0; i < szz(best); i++)
            if (!i)cout << best[i] + 1;
            else cout << " " << best[i] + 1;
        cout << endl;

        vector < int > worst = findWorstRoot(best);


        cout << "Worst Roots : ";
        for (int i = 0; i < szz(worst); i++)
            if (!i)cout << worst[i] + 1;
            else cout << " " << worst[i] + 1;
        cout << endl;
    }

}