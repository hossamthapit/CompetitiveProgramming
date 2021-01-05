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


int v[11][2];
int dp[1001][1001];
int path[1001][1001];

int solve(int i, int j) {
    if (i >= j)return 0;

    int& ret = dp[i][j];
    if (~ret)return ret;
    ret = 1e9;

    for (int k = i; k < j; k++) {
        int r = solve(i, k) + solve(k + 1, j) + v[i][0] * v[k][1] * v[j][1];
        if (r < ret) {
            ret = r;
            path[i][j] = k;
        }
    }
    return ret;
}

void print(int i, int j) {
    if (i == j)cout << "A" << i + 1;
    else {
        cout << "(";
        print(i, path[i][j]);
        cout << " x ";
        print(path[i][j] + 1, j);
        cout << ")";
    }
}


int main() {
    file();

    int n, k = 1;
    while (cin >> n && n) {
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < n; i++)cin >> v[i][0] >> v[i][1];
        solve(0, n - 1);

        cout << "Case " << k++ << ": ";
        print(0, n - 1);
        cout << endl;
    }

}