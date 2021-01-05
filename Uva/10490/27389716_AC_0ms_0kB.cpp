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

bool isPrime(ll x) {
    if (x == 1)return 0;
    if (x % 2 == 0 && x != 2)return 0;
    for (ll i = 3; i * i <= x; i += 2)
        if (x % i == 0)return 0;
    return 1;
}

set < ll > sum(ll x) {
    set < ll > st;
    for (ll i = 1; i*i <= x; i++) {
        if (x % i == 0)st.insert(i), st.insert(x / i);
    }
    return st;
}

int main() {
    file();


    ll n;
    while (cin >> n && n) {
        ll ans = ll(pow(2, n - 1) * (pow(2, n) - 1));
        set < ll > st1 = sum(pow(2, n - 1));
        set < ll > st2 = sum(pow(2, n) - 1);

        set < ll > st3;
        for (auto e : st1)
            for (auto f : st2)
                st3.insert(e * f),st3.insert(e),st3.insert(f);

        ll s = -ans;
        for (auto e : st3)s += e;

        if (isPrime(n) && s == ans )cout << "Perfect: " << ans << "!" << endl;
        else {
            if (!isPrime(n))cout << "Given number is NOT prime! NO perfect number is available." << endl;
            else cout << "Given number is prime. But, NO perfect number is available." << endl;
        }
    }

}