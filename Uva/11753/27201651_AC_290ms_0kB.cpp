#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
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

int n, k;
vector < int > v;
int mem[10005][25][25];

int solve(int l = 0, int cntL = 0 , int cntR = 0 ) {

    if (cntL + cntR > k)return 25;
    if (l >= n - (l + cntL) - 1 + cntR)return 0;

    int& ret = mem[l][cntL][cntR];

    if (ret != -1)
        return ret;
    ret = 25;

    if (v[l] == v[n - (l+cntL) - 1 + cntR])
        ret = min(solve(l + 1, cntL , cntR), ret);

    ret = min(ret, solve(l + 1, cntL , cntR + 1) + 1);
    ret = min(ret, solve(l, cntL + 1, cntR) + 1);
  
    return ret;
}

int main() {
    file();

    int T , t = 1;
    cin >> T;
    while (t <= T) {
        cin >> n >> k;
        memset(mem, -1, sizeof mem);
        v.resize(n);
        for (auto& e : v)cin >> e;

        int sol = solve();

        cout << "Case " << t++ << ": ";

        if (sol > k)cout << "Too difficult" << endl;
        else if (sol == 0)cout << "Too easy" << endl;
        else cout << sol << endl;

    }
    



}