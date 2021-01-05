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


int n;
vector < int > v;
int dp[55][55];

int solve(int l, int r) {

    if (l+1 >= r)return 0;

    int& ret = dp[l][r];
    if (ret != -1)return ret;
    ret = 1e7;

    for (int i = l + 1; i <= r - 1; i++) {
        int val1 = 0, val2 = 0;

        if (l < i - 1)val1 = v[i] - v[l];
        if (i + 1 < r)val2 = v[r] - v[i];
        ret = min(solve(l, i) + solve(i, r) + val1 + val2, ret);
    }
    return ret;
}

int main() {
    file();

    int m;
    while (cin >> m && m) {
        memset(dp, -1, sizeof dp);
        cin >> n;
        v.resize(n + 2);

        for (int i = 1; i <= n; i++)
            cin >> v[i];
        
        if (!n) {
            cout << "The minimum cutting is " << 0 << "." << endl;
            continue;
        }

        v[0] = 0;
        v[n + 1] = m;
        cout << "The minimum cutting is " << solve(0, n+1) + m << "." << endl;
    }



}