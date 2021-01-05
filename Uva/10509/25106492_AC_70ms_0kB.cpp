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

    double n, sq;

    cout << fixed << setprecision(4);
    while (cin >> n && n) {

        ll l = 0, r = 1000000, mid;


        while (l <= r) {
            mid = (l + r)/2;
            if (mid * mid * mid <= n) {
                sq = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }

        double dx = ( (1 / 3.0) *(n - (sq * sq * sq)) ) / (sq * sq);
        cout << sq + dx << endl;

    }



}