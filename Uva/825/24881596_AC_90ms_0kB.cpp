#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}


int depth[1001][1001], n, m , sol;
bool vis[1001][1001];
int ar[1001][1001] ;


bool valid(int i, int j) {
    return (i >= 1 && j >= 1 && i <= n && j <= m);
}

ll bfs() {
    queue < pair < int, int > > q;
    q.push({ 1,1 });
    depth[1][1] = 0;
    
    while (szz(q)) {
        pair < int, int  > p = q.front();
        q.pop();
        if (vis[p.first][p.second])continue;
        vis[p.first][p.second] = 1;

        for (int i = 0; i < 4; i++) {
            int x = p.first + dx[i], y = p.second + dy[i];
            if (valid(x, y) && !vis[x][y]) {
                depth[x][y] = depth[p.first][p.second] + 1;
                q.push({ x,y });
            }
        }
    }
    return depth[n][m];
}

ll solve2(int r, int c , int k = 0 ) {
    if (!valid(r, c) || ar[r][c] || k > sol)return 0;
    if (r == 1 && c == 1)return 1;

    ll ret =  0;

    for (int i = 0; i < 4; i++) {
        int ans = solve2(r + dx[i], c + dy[i], k + 1);
        ret += ans;
    }    
    return ret;
}

int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        
        memset(vis, 0, sizeof vis);
        memset(ar, 0, sizeof ar);

        cin >> n >> m;
        if (n == 4)
            int i = 0;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            stringstream str(s);
            int row, col;
            str >> row;
            while (str >> col) {
                ar[row][col] = 1;
            }
        }

        sol = bfs();
        cout << solve2(n, m , 0) << endl;
        if(t)cout << endl;
    }
}