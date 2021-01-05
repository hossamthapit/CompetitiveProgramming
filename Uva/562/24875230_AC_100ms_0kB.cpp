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

ll n, total = 0;
vector < int > v;

ll memo[101][30001];

ll solve(int idx, ll sum) {
    if (idx == n) {
        return 0;
    }

    ll& ret = memo[idx][sum];
    if (~ret)return ret;
    ret = -1e7;

    if (sum + v[idx] <= total) {
        ret = max(ret, solve(idx + 1, sum + v[idx])+v[idx]);
    }
    ret = max(ret, solve(idx + 1, sum));

    return ret;
}

int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        ll sum = 0;
        memset(memo, -1, sizeof memo);
        cin >> n;
        v.resize(n);
        for (auto& e : v)cin >> e, sum += e;
        total = (sum + 1) / 2;

        ll sec = solve(0, 0);
        ll fir = sum - sec;
        cout << ll(abs(fir-sec)) << endl;
    }


}