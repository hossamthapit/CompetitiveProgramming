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


string s, k;
int memo[101][101];

int solve(int i, int j) {
    if (i >= szz(s) || j >= szz(k))return 0;

    int& ret = memo[i][j];
    if (~ret)return ret;
    ret = 0;

    if (s[i] == k[j])
        ret = solve(i + 1, j + 1) + 1;
    ret = max(ret, solve(i + 1, j));
    ret = max(ret, solve(i, j + 1));
    return ret;
}
int main() {
    file();

    int i = 1;
    while (getline(cin,s)&& s!="#") {
        getline(cin, k);
        memset(memo, -1, sizeof memo);
        cout << "Case #" << i++ << ": you can visit at most " << solve(0,0) << " cities." << endl;
    }

}   