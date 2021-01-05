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
    //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}

ll gcd(ll x, ll y) {
    if (!x)return y;
    return gcd(y % x, x);
}

ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;
}

int main() {
    file();

    ll a, b, n, t, m;
    while (cin >> n >> m) {

        ll ans = 0;
        bitset < 16  > bts;
        vector < ll > v(m), vv(m);
        for (auto& e : v)cin >> e;

        for (int i = 1; i < (1 << m); i++) {
            bts = i;
            ll lc = 1, c = 0;
            for (int k = 0; k < m; k++) {
                if (bts[k]) {
                    c++;
                    lc = lcm(lc, v[k]);
                }
            }
            if (c & 1)ans += n / lc;
            else ans -= n / lc;
        }
        cout << n - ans << endl;
    }


}