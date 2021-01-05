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

int memo[100][25000], n, half, mx = 0;
vector < int > v;

void solve(int idx, int sum = 0) {

    if (sum <= half)mx = max(mx, sum);
    if (idx == n || sum > half)return;

    if (memo[idx][sum])return;

    solve(idx + 1,sum);
    solve(idx + 1, sum + v[idx]);

    memo[idx][sum] = 1;
}

int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        memset(memo, 0, sizeof memo);
        cin >> n;
        v.resize(n); mx = 0; half = 0;

        for (auto& e : v)cin >> e, half += e;

        int total = half;
        half /= 2;
        solve(0, 0);
        total -= mx;
        cout << total - mx << endl;
    }


}