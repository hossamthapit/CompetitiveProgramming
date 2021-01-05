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

int k, m, w;
double dp[1001][101] , p;

double solve(int i, int c) {
    if (c == 0)
        return i % 2 == 0;

    double& ret = dp[i][c];
    if (ret == ret)return ret;
    ret = 0;

    ret = p * solve(i + 1, c - 1) + (1 - p) * solve(i, c - 1);
    return ret;
}

int main() {
    file();

    while (scanf("%d%d%d", &m, &w, &k) && (m + w)) {
        memset(dp, -1, sizeof dp);
        p = (m * 1.) / (m + w);

        printf("%0.7lf\n", solve(0, k));
    }
}