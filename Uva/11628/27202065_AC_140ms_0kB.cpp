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

ll gcd(ll x, ll y) {
    if (!x)return y;
    return gcd(y % x, x);
}

int main() {
    file();

    // trick !  last round will have the biggest effect

    int n, m , a;
    while (cin >> n >> m && n && m) {
        vector < int > v(n);
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                cin >> a;
            }
            v[i] = a;
            sum += a;
        }


        for (int i = 0; i < n; i++) {
            ll _gcd = gcd(sum, v[i]);
            cout << v[i] / _gcd << " / " << sum / _gcd << endl;
        }
    }

}