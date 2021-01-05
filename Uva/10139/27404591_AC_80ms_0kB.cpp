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



map < int , int > fact(int x) {

    map < int, int > mp;
    while (x && x % 2 == 0) {
        mp[2]++; x /= 2;
    }

    for(ll i = 3 ; i *i <= x ;i+=2)
        while (x && x % i == 0) {
            x /= i;
            mp[i]++;
        }
    if (x > 1)mp[x]++;
    return mp;
}



int main() {
    file();
    
    ll n, m;
    while (cin >> n >> m) {

        map < int, int > mp2 = fact(m);

        bool valid = 1;


        for (auto e : mp2) {

            int num = e.first;
            int k = e.second;

            while (k > 0) {
                if (num > n) {
                    valid = 0; break;
                }
                k -= (n / num);
                num *= e.first;
            }
        }

        if (!valid)
            cout << m << " does not divide " << n << "!" << endl;
        else
            cout << m << " divides " << n << "!" << endl;
    }
}