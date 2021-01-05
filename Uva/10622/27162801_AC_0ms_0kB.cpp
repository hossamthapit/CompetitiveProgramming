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

map < ll, ll > mp;

void factorM(ll x) {
    while (x && x % 2 == 0) { x /= 2; mp[2]++; }
    for(ll i = 3 ; i *i <= x ;i+=2)
        while (x && x % i == 0) {
            x /= i;
            mp[i]++;
        }
    if (x > 1)mp[x]++;
}

ll gcd(ll x, ll y) {
    if (!x)return y;
    return gcd(y % x, x);
}

int main() {
    file();


    int n;
    while (cin >> n && n) {

        mp.clear();
        factorM(abs(n));

        ll gd = (*mp.begin()).second, sum = 0;
        
        
        for (auto e : mp)
            gd = gcd(gd, e.second);


        set < ll > GCDs;
        for (ll i = 1; i * i <= gd; i++)
            if (gd % i == 0)
                GCDs.insert(i), GCDs.insert(gd / i);

        //cout << gd << endl;
        //for (auto e : mp)
        //    cout << e.first << " " << e.second << endl;

        ll ans = 1;
        for (auto e : GCDs) {

            ll sum1 = INT_MAX;
            for (auto f : mp)
                sum1 = min(f.second / e, sum1);

            if (n > 0)ans = e;
            else if (sum1 % 2 == 1)
                ans = max(ans,sum1);
            //cout << e << " " << sum1 << " " << ans << endl;
        }

        cout << ans << endl;
        //cout << endl;
    }

}