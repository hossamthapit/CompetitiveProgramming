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

int n, k;
int memo[10000][101];
vector < int > v;

int solve(int i, int mod) {
    if (i == n && mod%k==0)return 1;
    if (i == n)return 0;

    int& ret = memo[i][mod];
    if (~ret)return ret;
    ret = 0;

    ret |= solve(i + 1, (v[i] + mod)%k );
    ret |= solve(i + 1, (mod - v[i])%k );

    return ret;
}
int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        memset(memo, -1, sizeof memo);
        cin >> n >> k;
        v.resize(n);
        for (auto& e : v)cin >> e;
        if (solve(0, 0))cout << "Divisible" << endl;
        else cout << "Not divisible" << endl;
    }

}   