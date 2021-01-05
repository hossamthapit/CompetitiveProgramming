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


int main() {
    file();

    ll n, a, b;
    while (cin >> n >> a >> b && n) {
        map < ll, ll > mp;

        ll cur = 0 , next , killed = 0;
        while (1) {
            next = a * cur %n *cur %n+ b % n;
            mp[next]++;
            if (mp[next] == 2) { killed++;}
            else if (mp[next] == 3)break;
            cur = next;
        }
        cout << n - killed << endl;
    }



}