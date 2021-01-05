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


struct point {
    int x, y, dist;
};

vector < int > v;
vector < int > idxOf;
vector < point > swps;
map < pair < int, int >, bool > mp , change;

bool cmp(point x, point y) {
    pair < int, pair < int, int > > p1, p2;
    p1.first = x.y - x.x; p1.second.first = idxOf[x.x]; p1.second.second = idxOf[x.y];
    p2.first = y.y - y.x; p2.second.first = idxOf[y.x]; p2.second.second = idxOf[y.y];
    return p1 < p2;
}

int main() {
    file();

    ll n, m , T = 1;
    while (cin >> n >> m && (n || m)) 
        cout << "Case " << T++ << ": " << n * (n - 1) / 2 * m * (m - 1) / 2 << endl;

}