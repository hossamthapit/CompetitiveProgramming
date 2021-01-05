#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
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

vector < pair < int, int > > objects;

int memo[1001][33], n;

int solve(int idx, int still) {
    if (idx == n)return 0;

    int& ret = memo[idx][still];
    if (~ret)return ret;
    ret = 0;

    if (objects[idx].second <= still)
        ret = max(ret, solve(idx + 1, still - objects[idx].second) + objects[idx].first);
    ret = max(ret, solve(idx + 1, still));
    return ret;
}

int main() {
    file();

    int t;
    cin >> t;
    while (t--) {

        cin >> n;
        objects.resize(n);
        for (auto& e : objects)cin >> e.first >> e.second;

        int peo, can;
        ll total = 0;
        cin >> peo;
        while (peo--) {
            memset(memo, -1, sizeof memo);
            cin >> can;
            total += solve(0, can);
        }
        cout << total << endl;
    }

}