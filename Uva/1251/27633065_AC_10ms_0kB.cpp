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


int bfs(string from, string to, vector < pair < string, string > >& v) {
    queue < pair < string, int > > q;
    map < string, bool > vis;
    q.push({ from,0 });
    while (szz(q)) {
        string u = q.front().first; 
        int  cost = q.front().second; q.pop();
        if (vis[u])continue;
        if (u == to)return cost;
        vis[u] = 1;
        for (auto e : v) {
            string temp = u , temp2 = u;
           
            auto it = temp2.find(e.first);
            while (it != string::npos) {
                int en = it + szz(e.first);
                temp.replace(temp.begin() + it, temp.begin() + en, e.second);
                temp2.replace(temp2.begin() + it, temp2.begin() + en, string(szz(e.second),'?'));
                it = temp2.find(e.first);
            }
            if(szz(temp) <= szz(to))
                q.push({temp,cost+1});
        }
    }
    return -1;
}

int main() {
    init();
    
    
    int n;
    while (cin >> n && n) {
        vector < pair < string, string > > v(n);
        for (auto& e : v)cin >> e.first >> e.second;
        string  from, to;
        cin >> from >> to;
        auto it = from.find("ahmed");
        cout << bfs(from, to, v) << endl;
    }


}
