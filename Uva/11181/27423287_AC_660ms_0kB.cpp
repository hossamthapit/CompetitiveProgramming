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

int n;
vector < double > v;
double choiceProp(int mask) {

    double ret = 1;
    for (int i = 0; i < n; i++)
        if (mask & (1 << i))ret *= v[i];
        else ret *= (1 - v[i]);
    return ret;
}

int main() {
    file();
    
    int m , T = 1;
    while (cin >> n >> m && n ) {

        cout << "Case " << T++ << ":" << endl;
        v.resize(n);
        for (auto& e : v)cin >> e;


        for (int j = 0; j < n; j++) {
            double p1 = 0, p2 = 0;
            for (int i = 0; i < (1 << n); i++) {
                bitset < 21 > bts = i;
                if (bts.count() == m) {

                    p2 += choiceProp(i);
                    if (bts[j])p1 += choiceProp(i);
                }
            }
            cout << fixed << setprecision(6) <<  p1 / p2 << endl;
        }



    }
}