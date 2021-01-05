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


ll memo[1001][1001] , n;
vector < int > v;

ll solve(int idx , int last) {
    if (idx == n)return 0;

    ll& ret = memo[idx][last];
    if (~ret)return ret;

    ret = solve(idx + 1, last);
    if(v[idx]>v[last])
         ret = max(ret,solve(idx+1, idx)+1);

    return ret;
}
void build(int idx, int last) {
    if (idx == n)return;

    int ch1 = solve(idx + 1, last), ch2 = -1;
    if (v[idx] > v[last])
        ch2 = solve(idx + 1, idx) + 1;

    int optimal = solve(idx, last);

    if (ch1 == optimal)
        build(idx + 1, last);
    else {
        cout << v[idx] << endl;
        build(idx + 1, idx);
    }
}

int main() {
    file();

    int t;
    cin >> t;
    while (t--) {
        memset(memo, -1, sizeof memo);
        string x;
        v.clear();
        while (getline(cin,x)) {
            if (x == "" && szz(v)) break;
            else if (x == "")continue;
            stringstream str(x);
            int num;
            str >> num;
            v.push_back(num);
        }

        n = szz(v);
        v.push_back(-1);
        cout << "Max hits: " << solve(0,n) << endl;
        build(0,n);
        if (t)cout << endl;

    }
 }