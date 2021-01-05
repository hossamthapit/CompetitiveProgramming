#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define rt return 
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file() {
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

int n;
vector < vector < int > > adj;
vector < int > col;
vector < int > temp, ans;

void solve(int idx = 0) {

    if (idx == n) {
        if (szz(temp) > szz(ans))
            ans = temp;
        return;
    }

    int ok = 0;
    for (auto e : adj[idx]) {
        if (col[e] == 2) {
            ok = 1;
            break;
        }
    }

    if (!ok) {
        temp.push_back(idx+1);
        col[idx] = 2;
        solve(idx + 1);
        temp.pop_back();
    }
    col[idx] = 1;
    solve(idx + 1);
}

int main() {
    file();

    int T;
    cin >> T;
    while(T--){
        int m;
        cin >> n >> m;
        adj.clear();
        col.clear();
        ans.clear();
        adj.resize(n);
        col.resize(n);

        while (m--) {
            int a, b; cin >> a >> b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        solve();
        cout << szz(ans) << endl;
        for (int i = 0; i < szz(ans); i++)
            if (!i)cout << ans[i];
            else cout << " " << ans[i];
        cout << endl;
    }



}