#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
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


map < int, int > mp;

void fact(ll x) {

    while (x && x % 2 == 0) {
        mp[2]++; x /= 2;
    }

    for(ll i = 3 ; i *i <= x ;i+=2)
        while (x && x % i == 0) {
            x /= i;
            mp[i]++;
        }
    if (x > 1)mp[x]++;
}

int main() {
    file();
    
    ll n , m;
    string s;
    while (getline(cin, s) && s!="0") {
        stringstream str(s);
        mp.clear();

        ll num = 1;
        while (str >> n && str >> m) {
            num *= pow(n, m);
        }
        fact(num-1);
        vector < int > v;
        for (auto e : mp) {
            v.push_back(e.second);
            v.push_back(e.first);
        }
        reverse(all(v));
        for (int i = 0; i < szz(v); i++) {
            if (i == szz(v) - 1)cout << v[i];
            else cout << v[i] << " ";
        }
        cout << endl;
    }
    
    

}