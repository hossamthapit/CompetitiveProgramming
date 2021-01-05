#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
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


int main() {
    file();

    while (1) {
        vector < stack < string > > v;

        for (int i = 0; i < 52; i++) {
            string s; cin >> s;
            if (i == 0 && s == "#")exit(0);
            stack < string > stk;
            stk.push(s);
            v.push_back(stk);
        }

        for (int i = 0; i < szz(v); i++) {
            if (i >= 3 && (v[i].top()[0] == v[i - 3].top()[0] || v[i].top()[1] == v[i - 3].top()[1])) {
                v[i - 3].push(v[i].top());
                v[i].pop();
                if (!szz(v[i]))v.erase(v.begin() + i, v.begin() + i + 1);
                i -= 4;
            }
            else if (i >= 1 && (v[i].top()[0] == v[i - 1].top()[0] || v[i].top()[1] == v[i - 1].top()[1])) {
                v[i - 1].push(v[i].top());
                v[i].pop();
                if (!szz(v[i]))v.erase(v.begin() + i, v.begin() + i + 1);
                i -= 2;
            }
        }

        if(szz(v)==1)cout << szz(v) << " pile remaining:";
        else cout << szz(v) << " piles remaining:";
        for (auto e : v)
            cout << " " << szz(e);
        cout << endl;
   }
    
}