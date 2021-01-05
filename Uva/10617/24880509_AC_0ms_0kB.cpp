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


ll memo[66][66], n , m;
string s;



ll solve(int l, int r) {
    if (l > r)return 0;
    if (l == r)return 1;

    ll& ret = memo[l][r];
    if (~ret)return ret;
    ret = 0;

    if (s[l] == s[r])
        ret += solve(l + 1, r - 1) + 1;

    ret += solve(l + 1, r);
    ret += solve(l, r - 1);
    ret -= solve(l + 1, r - 1);

    return ret;
}


int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        memset(memo, -1, sizeof memo);
        cin >> s;
        cout << solve(0, szz(s) - 1) << endl;

    }
 }