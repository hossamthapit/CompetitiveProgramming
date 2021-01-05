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

int main() {
    file();


    int n;
    while (cin >> n && n) {

        mp.clear();
        factorM(abs(n));
        vector < int > ans;
        if (n < 0)ans.push_back(-1);
        for (auto& e : mp)
            while (e.second--)
                ans.push_back(e.first);

        cout << n << " = ";
        for (int i = 0; i < szz(ans); i++)
            if (i == szz(ans) - 1)cout << ans[i];
            else cout << ans[i] << " x ";
        cout << endl;
        
    }

}