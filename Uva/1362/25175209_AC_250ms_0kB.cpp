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
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

ll dp[300][300] , mod = 1e9;
string s;

ll solve(int i, int j) {

    if (i == j)return 1;
    if (i > j)return 0;

    ll& ret = dp[i][j];
    if (~ret)return ret;
    ret = 0;

    if (s[i] != s[j])return 0;

    for (int k = i+2; k <= j; k++) {
        if (s[k] == s[i])
            ret += solve(i+1, k - 1) * solve(k, j);
        ret %= mod;
    }

    return ret;
}

int main() {
    file();

    while (cin >> s) {
        
        memset(dp, -1, sizeof dp);
        cout << solve(0, szz(s) - 1) << endl;

    }


}