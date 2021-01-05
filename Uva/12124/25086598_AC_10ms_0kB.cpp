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


int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        ll n, budget;
        map < string , vector < pair <  ll , ll > > > mp;
        set < string > names;
        cin >> n >> budget;

        string name, temp;
        ll price, power;

        for (int i = 0; i < n; i++) {
            cin >> name >> temp >> price >> power;
            mp[name].push_back({ price,power });
            names.insert(name);
        }

        ll l = 0, r = 1e18, mid, ans;
        while (l <= r) {
            mid = (l + r) / 2;
            ll total = 0;
            for (auto e : names) {
                ll mn = INT_MAX;
                for (auto k : mp[e]) {
                    if (k.second >= mid)
                        mn = min(mn, k.first);
                }
                total += mn;
            }
            if (total <= budget)
                ans = mid, l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans << endl;;
                
    }

     
}