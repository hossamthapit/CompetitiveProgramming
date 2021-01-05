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

int n = 9;
vector < int > indeg , tempIndeg;
vector < set < pair < int , int > > > adj;
map < pair < int, int >, int > mp;
map < int, int > cost;
vector < int > best;
int ans = 0;

bool isBest(int u) {
    for (auto e : best)
        if (e == u)
            return 1;
    return 0;
}

void findBestRoot() {

    // create indeg for each node before use it :)

    queue<int> q;
    int vertices = n;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 1)
            q.push(i), vertices--;

    while (szz(q) + vertices > 2) {

        int sz = q.size();

        while (sz--) {

            int t = q.front();
            q.pop();

            for (auto j : adj[t])
                if (--indeg[j.first] == 1)
                    q.push(j.first), vertices--;
        }
    }

    vector<int> res;
    while (!q.empty()) {
        best.push_back(q.front());
        q.pop();
    }
}


void solve() {

    queue < int > q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 1)
            q.push(i);

    vector < vector < int > > childsAns(n);

    while (szz(q)) {

        int sz = szz(q);
        while (sz--) {
            int u = q.front(); q.pop();

            for (auto e : adj[u]) {
                indeg[e.first]--;

                childsAns[e.first].push_back(cost[u] + e.second);

                if ((indeg[e.first] == 1 && !isBest(e.first)) || (indeg[e.first]==0 && isBest(e.first))) {
                    if(!isBest(e.first))
                        q.push(e.first);

                    sort(all(childsAns[e.first]));
                    cost[e.first] = childsAns[e.first].back();

                    int a1 = childsAns[e.first].back(), a2 = 0;
                    childsAns[e.first].pop_back();
                    if(szz(childsAns[e.first]))
                        a2 = childsAns[e.first].back();
                    ans = max(ans, a1 + a2);
                }
            }

        }
    }

    for (auto e : childsAns) {
        sort(all(e));
        if (szz(e) > 1)
            ans = max(ans, e[szz(e) - 1] + e[szz(e) - 2]);
    }

    for(auto k : best) {
        for (auto e : childsAns[k])
            cost[k] = max(e, cost[k]);
    }

}


int start(vector < pair < pair < int , int > , int > > &v , int k) {
    
    n = k;

    indeg = tempIndeg = vector < int >(n);
    adj = vector < set < pair < int, int > > >(n);
    mp.clear();
    cost.clear();
    best.clear();
    ans = 0;

    for (auto e : v) {
        int a = e.first.first, b = e.first.second, c = e.second;
        
        a--, b--;

        indeg[a]++;
        indeg[b]++;
        adj[a].insert({ b,c });
        adj[b].insert({ a,c });
        mp[{a, b}] = mp[{b, a}] = max(mp[{b, a}], c);
    }

    tempIndeg = indeg;
    findBestRoot();
    indeg = tempIndeg;

    if (szz(best) == 2) {
        adj[best[0]].erase({ best[1] , mp[{best[0],best[1]}] });
        adj[best[1]].erase({ best[0] , mp[{best[0],best[1]}] });
        solve();

        ans = max(ans, cost[best[0]] + cost[best[1]] + mp[{best[0], best[1]}]);
    }
    else
        solve();

    return ans;
}


int main() {
    file();

    string s;
    int a, b, c;
    vector < pair < pair < int, int >, int > > temp;

    int mx = 0;

    while (getline(cin, s)) {
        if (s == "") {
            cout << start(temp , mx) << endl;
            temp.clear();
            mx = 0;
            continue;
        }
        stringstream str(s);
        str >> a >> b >> c;
        temp.push_back({ {a,b},c });
        mx = max({ mx,a,b });
    }

    cout << start(temp, mx) << endl;

}