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


int n;
string s;
int memo[1001][1001];

int solve(int i, int j) {
    if (i >= j)return 0;

    int& ret = memo[i][j];
    if (~ret) return ret;
    ret = 1e6;

    ret = min(solve(i + 1, j) + 1, ret);
    ret = min(solve(i, j - 1) + 1, ret);
    ret = min(solve(i + 1 , j - 1) + 1, ret);
    
    if(s[i]==s[j])
        ret = min(solve(i + 1, j - 1) , ret);

    return ret;
}

int main() {
   // file();

    int t , i = 1;
    cin >> t;
    while (t--) {
        memset(memo, -1, sizeof memo);
        cin >> s;
        cout << "Case " << i++ << ": " <<  solve(0,szz(s)-1) << endl;

    }

}